#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PlayerController.h"
#include "MockPlayer.h"
#include "MockCardCollection.h"
#include "MockOldMaidTurnView.h"


using testing::Return;


TEST(PlayerControllerTests, take_turn) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    PlayerController pc(&mPlayer, &view);

    MockCardCollection cards;
}


TEST(PlayerControllerTests, get_player) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    PlayerController pc(&mPlayer, &view);

    EXPECT_EQ(&mPlayer, pc.getPlayer());
}


TEST(PlayerControllerTests, is_out) {
    MockPlayer mPlayer;
    MockOldMaidTurnView view;
    PlayerController pc(&mPlayer, &view);

    MockCardCollection cards;

    EXPECT_CALL(mPlayer, getHand())
        .Times(1)
        .WillOnce(Return(&cards));

    EXPECT_CALL(cards, size())
        .Times(1)
        .WillOnce(Return(0));

    EXPECT_EQ(true, pc.isOut());
}
