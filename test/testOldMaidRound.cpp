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
    r.play();

    EXPECT_EQ(hand1, players[0]->getHand());
    EXPECT_EQ(hand2, players[1]->getHand());
}



TEST(OldMaidRoundTests, play_simple) {
}
