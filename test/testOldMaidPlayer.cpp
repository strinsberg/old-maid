#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "OldMaidPlayer.h"
#include "MockPlayer.h"
#include "MockCardCollection.h"
#include "MockOldMaidTurnView.h"


using testing::Return;


TEST(OldMaidPlayerTests, take_turn) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    OldMaidPlayer pc(&mPlayer, &view);

    MockCardCollection cards;
}


TEST(OldMaidPlayerTests, get_player) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    OldMaidPlayer pc(&mPlayer, &view);

    EXPECT_EQ(&mPlayer, pc.getPlayer());
}


TEST(OldMaidPlayerTests, is_out) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    OldMaidPlayer pc(&mPlayer, &view);

    MockCardCollection cards;

    EXPECT_CALL(mPlayer, getHand())
        .Times(1)
        .WillOnce(Return(&cards));

    EXPECT_CALL(cards, size())
        .Times(1)
        .WillOnce(Return(0));

    EXPECT_EQ(true, pc.isOut());
}
