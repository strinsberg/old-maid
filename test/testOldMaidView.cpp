#include <gtest/gtest.h>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "OldMaidView.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"


TEST(TestOldMaidView, turn_info) {
    std::stringstream ss;
    // Should I mock out players?
    //OldMaidView view(players, ss);
    
    EXPECT_EQ("""=== Steve's Turn ===\n\n-- Hand Sizes --\nSteve: 2\nComp1: 2\n\n-- Your Cards --\nAH 2H\n""", ss.str());
}


TEST(TestOldMaidView, pick_card) {
    std::stringstream ss;
    OldMaidView view(nullptr, ss);

    view.pickCard();
    EXPECT_EQ("Choose card: ", ss.str());
}


TEST(TestOldMaidView, result) {
    //std::stringstream ss;
    //OldMaidView view(players, ss);
}


TEST(TestOldMaidView, end_round) {
    std::stringstream ss;
    Player steve("Steve");
    std::vector<Player*> players{&steve};
    OldMaidView view(&players, ss);

    view.endRound(0);
    EXPECT_EQ("=== Round Over ===\n\nOld Maid: Steve\n", ss.str());
}


TEST(TestOldMaidView, end_round_throws) {
    std::stringstream ss;
    Player steve("Steve");
    std::vector<Player*> players{&steve};
    OldMaidView view(&players, ss);

    EXPECT_THROW(view.endRound(20), std::out_of_range);
    EXPECT_THROW(view.endRound(-1), std::out_of_range);
}
