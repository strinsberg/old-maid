#include <gtest/gtest.h>
#include "Player.h"
#include "CardCollection.h"
#include "Suit.h"

TEST(PlayerTests, new_player_get_name) {
    Player p("Steve");

    EXPECT_EQ(p.getName(), "Steve");
}


TEST(PlayerTests, set_hand_get_hand) {
    Player p("Steve");
    CardCollection* h = new CardCollection();

    p.setHand(h);

    EXPECT_EQ(p.getHand(), h);
    EXPECT_EQ(p.getHand()->size(), 0);
}


TEST(PlayerTest, update_score) {
    Player p("Steve");

    int score = p.updateScore(10);
    EXPECT_EQ(score, 10);
    EXPECT_EQ(p.getScore(), 10);

    score = p.updateScore(-25);
    EXPECT_EQ(score, -15);
    EXPECT_EQ(p.getScore(), -15);
}

