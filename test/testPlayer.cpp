#include <gtest/gtest.h>
#include "Player.h"
#include "Hand.h"


TEST(PlayerTests, new_player_get_name) {
    Player p("Steve");

    EXPECT_EQ(p.getName(), "Steve");
    EXPECT_EQ(p.getHand(), nullptr);
}


TEST(PlayerTests, set_hand_get_hand) {
    Player p("Steve");
    Hand* h = new Hand();

    p.setHand(h);

    EXPECT_EQ(p.getHand(), h);
    EXPECT_EQ(p.getHand()->size(), 0);
}
