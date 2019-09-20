#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "OldMaidRound.h"
#include "MockInput.h"
#include "MockOldMaidView.h"
#include "MockDeck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Suit.h"


TEST(OldMaidRoundTests, new_round_setup_deck) {
    // setup players and hands
    Player steve("Steve");
    Player comp("Comp1");
    std::vector<Player*> players{&steve, &comp};

    Hand* hand1 = new Hand();
    Hand* hand2 = new Hand();
    std::vector<Hand*> hands{hand1, hand2};

    // setup mock deck and expect calls
    MockDeck mDeck;

    EXPECT_CALL(mDeck, shuffle())
        .Times(1);

    EXPECT_CALL(mDeck, findCard(12, Suit::CLUB))
        .Times(1)
        .WillOnce(testing::Return(0));

    EXPECT_CALL(mDeck, takeCard(0))
        .Times(1);

    EXPECT_CALL(mDeck, deal(2, 0))
       .Times(1)
       .WillOnce(testing::Return(hands));

    // Other mocks
    MockInput mInput;
    MockOldMaidView mView(&players);

    // create round and run expects
    OldMaidRound r(&mDeck, &players, &mInput, &mView);

    EXPECT_EQ(hand1, players[0]->getHand());
    EXPECT_EQ(hand2, players[1]->getHand());
}



TEST(OldMaidRoundTests, play_simple) {
    // setup players and hands
    Player steve("Steve");
    Player comp("Comp1");
    std::vector<Player*> players{&steve, &comp};

    Hand* hand1 = new Hand();
    Hand* hand2 = new Hand();
    std::vector<Hand*> hands{hand1, hand2};

    Card* c1 = new Card(1, Suit::HEART);
    Card* c2 = new Card(2, Suit::HEART);
    Card* c3 = new Card(1, Suit::SPADE);
    Card* c4 = new Card(2, Suit::SPADE);
    Card* maid = new Card(12, Suit::CLUB);

    hand1->addCard(c1);
    hand1->addCard(c2);
    hand2->addCard(c3);
    hand2->addCard(c4);
    hand2->addCard(maid);


    // setup mocks expect calls
    MockDeck mDeck;

    EXPECT_CALL(mDeck, deal(2, 0))
       .Times(1)
       .WillOnce(testing::Return(hands));

    MockInput mInput;

    EXPECT_CALL(mInput, getInt())
       .Times(3)
       .WillOnce(testing::Return(2))
       .WillRepeatedly(testing::Return(0));

    MockOldMaidView mView(&players);

    EXPECT_CALL(mView, turnInfo(0))
       .Times(2);

    EXPECT_CALL(mView, turnInfo(1))
       .Times(1);

    EXPECT_CALL(mView, pickCard())
       .Times(3);

    EXPECT_CALL(mView, result(testing::_, true, testing::_))
       .Times(2);

    EXPECT_CALL(mView, result(testing::_, false, testing::_))
       .Times(1);

    EXPECT_CALL(mView, endRound(0))
       .Times(1);

    // create round and run expects
    OldMaidRound r(&mDeck, &players, &mInput, &mView);
    r.play();
}
