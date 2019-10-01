#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "OldMaidPlayer.h"
#include "MockPlayer.h"
#include "MockCardCollection.h"
#include "MockOldMaidTurnView.h"
#include "MockDeck.h"
#include "MockInput.h"


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
    EXPECT_CALL(view, turnInfo(players))
        .Times(1);

    EXPECT_CALL(view, playerInfo(&player))
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

    EXPECT_CALL(cards, takeCard(2))
        .Times(1)
        .WillOnce(Return(new Card(4, Suit::HEART)));

    // Call take turn
    pc.takeTurn(&deck, players);
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
