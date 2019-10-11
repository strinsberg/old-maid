#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "OldMaidPlayer.h"
#include "MockPlayer.h"
#include "MockCardCollection.h"
#include "MockOldMaidTurnView.h"
#include "MockDeck.h"
#include "MockInput.h"
#include "CardCollection.h"
#include "Card.h"

using testing::Return;
using testing::_;


TEST(OldMaidPlayerTests, take_turn) {
    MockOldMaidTurnView view;
    MockInput input;

    MockPlayer player;
    OldMaidPlayer pc(&player, &view, &input);
    std::vector<Player*> players{&player, &player, &player};

    MockDeck deck;
    MockCardCollection cards;

    // Begin Turn output
    EXPECT_CALL(view, turnInfo())
        .Times(1);

    EXPECT_CALL(view, takeAction())
        .Times(1);

    // Get input
    EXPECT_CALL(input, getString())
        .Times(1)
        .WillOnce(Return("2"));

    // Take the card indicated by the input
    EXPECT_CALL(player, getHand())
        .WillRepeatedly(Return(&cards));

    Card const* card = new Card(4, Suit::HEART);

    EXPECT_CALL(cards, takeCard(2))
        .Times(1)
        .WillOnce(Return(card));

    // Add the card to the players hand and remove pairs
    EXPECT_CALL(player, sortHand(true, false))
        .Times(1);

    EXPECT_CALL(cards, addCard(card))
        .Times(1);

    EXPECT_CALL(cards, size())
        .Times(3)
        .WillOnce(Return(0))
        .WillRepeatedly(Return(1));

    // show result
    EXPECT_CALL(view, turnResult(card, false))
        .Times(1);

    // Call take turn
    pc.takeTurn(&deck, players);

    delete card;
}


TEST(OldMaidPlayerTests, update_hand) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    MockInput input;
    OldMaidPlayer pc(&mPlayer, &view, &input);

    // create a collection of cards and give it to the player
    // make sure it is sorted.
    // call updateHand
    // expect call to sort for player
    // then expect a certain makeup of cards when you are finished
    // might be possible to mock it out
    
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

    pc.updateHand();

    EXPECT_EQ(2, cards->size());

    std::vector<int> expect{6,7};
    for (int i = 0; i < cards->size(); i++) {
        EXPECT_EQ(expect.at(i), cards->getCard(i)->getValue());
    }
}


TEST(OldMaidPlayerTests, get_player) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    MockInput input;
    OldMaidPlayer pc(&mPlayer, &view, &input);

    EXPECT_EQ(&mPlayer, pc.getPlayer());
}


TEST(OldMaidPlayerTests, is_out) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    MockInput input;
    OldMaidPlayer pc(&mPlayer, &view, &input);

    MockCardCollection cards;

    EXPECT_CALL(mPlayer, getHand())
        .Times(1)
        .WillOnce(Return(&cards));

    EXPECT_CALL(cards, size())
        .Times(1)
        .WillOnce(Return(0));

    EXPECT_EQ(true, pc.isOut());
}
