#include <gtest/gtest.h>
#include <sstream>
#include "OldMaidView.h"

TEST(TestOldMaidView, new_view) {
   std::stringstream ss;
   OldMaidView v(ss);

   v.displayMessage("testing ...");
   
   EXPECT_EQ(ss.str(), "testing ...");
}


TEST(TestOldMaidView, display_hand) {
   std::stringstream ss;
   OldMaidView v(ss);

   v.displayHand();

   EXPECT_EQ(ss.str(), "AH, 2S, 10C, KD");
};


TEST(TestOLDMaidView, display_players) {
   std::stringstream ss;
   OldMaidView v(ss);

   v.displayPlayers();

   EXPECT_EQ(ss.str(), "P1:4, P2:6, P3:1"); 
}
