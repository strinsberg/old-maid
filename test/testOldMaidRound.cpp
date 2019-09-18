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


TEST(OldMaidRoundTests, new_round) {
    std::vector<Player*>* players;

    MockDeck mDeck;
    EXPECT_CALL(mDeck, shuffle()).Times(1);
    EXPECT_CALL(mDeck, findCard(12, Suit::CLUB)).Times(1).WillOnce(testing::Return(0));
    EXPECT_CALL(mDeck, takeCard(0)).Times(1);

    MockInput mInput;
    MockOldMaidView mView(players);
    OldMaidRound r(&mDeck, players, &mInput, &mView);
}


TEST(OldMaidRoundTests, play_simple) {
}
