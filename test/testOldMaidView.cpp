#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"


TEST(TestOldMaidView, turn_info) {
    //std::stringstream ss;
    // Should I mock out players?
    //OldMaidView view(players, ss);
}


TEST(TestOldMaidView, pick_card) {
    std::stringstream ss;
    OldMaidView view(nullptr, ss);

    view.pickCard();
    EXPECT_EQ(ss.str(), "Choose card: ");
}


TEST(TestOldMaidView, result) {
    //std::stringstream ss;
    //OldMaidView view(players, ss);
}


TEST(TestOldMaidView, end_round) {
    //std::stringstream ss;
    //OldMaidView view(players, ss);

    //view.endRound(0);
    //EXPECT_EQ(ss.str(), "=== Round Over ===\n\nOld Maid: NAME");
}
