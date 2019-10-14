#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>
#include "OldMaidPlayer.h"
#include "MockPlayer.h"
#include "MockCardCollection.h"
#include "MockOldMaidTurnView.h"
#include "MockDeck.h"
#include "MockInput.h"
#include "CardCollection.h"
#include "Card.h"

using testing::Return;
using testing::Throw;
using testing::_;

class TurnTests : public ::testing::Test {
 public:
    TurnTests() {
        pc = new OldMaidPlayer(&player, &view, &input);

        players.push_back(&player);
        players.push_back(&player);
        players.push_back(&player);

        card = new Card(4, Suit::HEART);
    }

    ~TurnTests() {
        delete card;
        delete pc;
    }

    void SetUp() {
        // Begin Turn output
        EXPECT_CALL(view, turnInfo())
            .Times(1);

        // Take the card indicated by the input
        EXPECT_CALL(player, getHand())
            .WillRepeatedly(Return(&cards));

        EXPECT_CALL(cards, takeCard(0))
            .Times(1)
            .WillOnce(Return(card));

        // Add the card to the players hand and remove pairs
        EXPECT_CALL(player, sortHand(true, false))
            .Times(1);

        EXPECT_CALL(cards, addCard(card))
            .Times(1);

        EXPECT_CALL(cards, takeAllCards(_))
            .Times(1)
            .WillOnce(Return(std::vector<Card const*>()));

        EXPECT_CALL(view, wait())
            .Times(1);
    }

    MockOldMaidTurnView view;
    MockInput input;
    MockDeck deck;
    MockCardCollection cards;
    MockPlayer player;

    OldMaidPlayer* pc;
    std::vector<Player*> players;
    Card const* card;
};


TEST_F(TurnTests, take_turn_false) {
    EXPECT_CALL(view, takeAction(&player))
        .Times(1);

    EXPECT_CALL(input, getString())
        .Times(1)
        .WillOnce(Return("1"));

    EXPECT_CALL(input, wait())
        .Times(1);

    EXPECT_CALL(cards, size())
        .Times(4)
        .WillRepeatedly(Return(1));

    EXPECT_CALL(view, turnResult(_, false))
        .Times(1);

    EXPECT_FALSE(pc->takeTurn(&deck, players));
}


TEST_F(TurnTests, take_turn_true) {
    EXPECT_CALL(view, takeAction(&player))
        .Times(1);

    EXPECT_CALL(input, getString())
        .Times(1)
        .WillOnce(Return("1"));

    EXPECT_CALL(input, wait())
        .Times(1);

    EXPECT_CALL(cards, size())
        .Times(4)
        .WillOnce(Return(1))
        .WillRepeatedly(Return(0));

    EXPECT_CALL(view, turnResult(_, true))
        .Times(1);

    EXPECT_TRUE(pc->takeTurn(&deck, players));
}


TEST_F(TurnTests, invalid_input) {
    EXPECT_CALL(input, getString())
        .Times(3)
        .WillOnce(Return("steve"))
        .WillOnce(Return("6"))
        .WillOnce(Return("1"));

    EXPECT_CALL(input, wait())
        .Times(1);

    EXPECT_CALL(view, takeAction(&player))
        .Times(3);

    EXPECT_CALL(cards, takeCard(5))
        .Times(1)
        .WillOnce(Throw(std::out_of_range("error")));

    EXPECT_CALL(view, badInput("Please enter a number"))
        .Times(1);

    EXPECT_CALL(view, badInput("Choose a number between 1 and 5"))
        .Times(1);

    EXPECT_CALL(cards, size())
        .Times(5)
        .WillOnce(Return(5))
        .WillRepeatedly(Return(1));

    EXPECT_CALL(view, turnResult(_, _))
        .Times(1);

    pc->takeTurn(&deck, players);
}


TEST_F(TurnTests, give_bad_input_too_many_times) {
    EXPECT_CALL(input, getString())
        .Times(10)
        .WillRepeatedly(Return("steve"));

    EXPECT_CALL(input, wait())
        .Times(1);

    EXPECT_CALL(view, takeAction(&player))
        .Times(11);

    EXPECT_CALL(view, badInput(_))
        .Times(10);

    EXPECT_CALL(cards, size())
        .Times(4)
        .WillRepeatedly(Return(1));

    EXPECT_CALL(view, turnResult(_, _))
        .Times(1);

    pc->takeTurn(&deck, players);
}


// Other tests ////////////////////////////////////////////////////////

class OtherPlayerTests : public ::testing::Test {
 public:
    OtherPlayerTests() {
        pc = new OldMaidPlayer(&mPlayer, &view, &input);
    }

    ~OtherPlayerTests() {
        delete pc;
    }

    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    MockInput input;
    OldMaidPlayer* pc;
};


TEST_F(OtherPlayerTests, update_hand) {
    CardCollection* cards = new CardCollection();
    cards->addCard(new Card(2, Suit::HEART));
    cards->addCard(new Card(2, Suit::SPADE));
    cards->addCard(new Card(6, Suit::HEART));
    cards->addCard(new Card(7, Suit::HEART));

    EXPECT_CALL(mPlayer, sortHand(true, false))
        .Times(1);

    EXPECT_CALL(mPlayer, getHand())
        .Times(1)
        .WillOnce(Return(cards));

    pc->updateHand();

    EXPECT_EQ(2, cards->size());

    EXPECT_EQ(6, cards->getCard(0)->getValue());
    EXPECT_EQ(7, cards->getCard(1)->getValue());

    delete cards;
}


TEST_F(OtherPlayerTests, get_player) {
    EXPECT_EQ(&mPlayer, pc->getPlayer());
}


TEST_F(OtherPlayerTests, is_out) {
    MockCardCollection cards;

    EXPECT_CALL(mPlayer, getHand())
        .Times(1)
        .WillOnce(Return(&cards));

    EXPECT_CALL(cards, size())
        .Times(1)
        .WillOnce(Return(0));

    EXPECT_EQ(true, pc->isOut());
}
