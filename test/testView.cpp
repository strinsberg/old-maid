#include <gtest/gtest.h>
#include "View.h"
#include "Player.h"
#include "Hand.h"


TEST(ViewTest, display_message) {
   std::stringstream ss;
   View v(ss);

   v.displayMessage("Please pick a card? ");
   
   EXPECT_EQ(ss.str(), "Please pick a card? ");
}
