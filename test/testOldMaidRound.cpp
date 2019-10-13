#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "OldMaidRound.h"
#include "MockView.h"
#include "MockPlayerController.h"
#include "MockPlayer.h"
#include "MockDeck.h"
#include "MockCardCollection.h"
#include "Card.h"
#include "Suit.h"


using testing::Return;
using testing::_;


TEST(OldMaidRoundTests, setup) {
    MockView view;

    MockPlayer p1;
    MockPlayerController pc1;
    std::vector<PlayerController*> players{&pc1, &pc1};

    MockCardCollection cards;
    std::vector<CardCollection*> hands{&cards, &cards};
    MockDeck deck;

    OldMaidRound round(&players, &deck, &view);

    // Removing queens from the deck
    EXPECT_CALL(deck, getCards())
        .Times(1)
        .WillOnce(Return(&cards));

    EXPECT_CALL(cards, findCard(12, _))
        .Times(3)
        .WillRepeatedly(Return(0));

    Card* q1 = new Card(12, Suit::HEART);
    Card* q2 = new Card(12, Suit::HEART);
    Card* q3 = new Card(12, Suit::HEART);

    EXPECT_CALL(cards, takeCard(0))
        .Times(3)
        .WillOnce(Return(q1))
        .WillOnce(Return(q2))
        .WillOnce(Return(q3));

    // Shuffle and deal
    EXPECT_CALL(deck, shuffle())
        .Times(1);

    EXPECT_CALL(deck, deal(2, 0))
        .Times(1)
        .WillOnce(Return(hands));

    // Set player hands
    EXPECT_CALL(pc1, getPlayer())
        .Times(2)
        .WillRepeatedly(Return(&p1));

    EXPECT_CALL(pc1, updateHand())
        .Times(2);

    EXPECT_CALL(p1, setHand(&cards))
        .Times(2);

    // Run setup
    round.setup();
}


TEST(OldMaidRoundTests, play) {
    MockView view;

    MockPlayer p1;
    std::vector<Player*> players{&p1, &p1, &p1};
    MockPlayerController pc1;
    std::vector<PlayerController*> pcs{&pc1, &pc1, &pc1};

    MockCardCollection cards;
    //std::vector<CardCollection*> hands{&cards, &cards};
    MockDeck deck;

    OldMaidRound round(&pcs, &deck, &view);

    EXPECT_CALL(view, beginRound(players))
        .Times(1);

    // Player 3 goes out in first loop and then Player 1
    // This means that Player 2 at idx 1 is the OldMaid after 4 turns
    EXPECT_CALL(pc1, takeTurn(&deck, _))
        .Times(4)
        .WillOnce(Return(false))
        .WillOnce(Return(false))
        .WillOnce(Return(true))
        .WillOnce(Return(true));

    EXPECT_CALL(view, endRound(players, 1))
        .Times(1);

    EXPECT_CALL(pc1, getPlayer())
        .WillRepeatedly(Return(&p1));

    EXPECT_CALL(view, gameStatus(_))
        .Times(4);

    EXPECT_CALL(p1, getHand())
        .WillRepeatedly(Return(&cards));

    EXPECT_CALL(cards, size())
        .WillRepeatedly(Return(1));

    // Run the round
    round.play();
}
