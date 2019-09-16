#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "Input.h"
#include "View.h"
#include "OldMaidView.h"


TEST(InputTests, get_input) {
   std::stringstream ssin, ssout;
   View* v = new OldMaidView(ssout);
   Input in(v, ssin);

   ssin << "4 unused";
   std::string input = in.getInput("Pick a card number: ");
   
   EXPECT_EQ(ssout.str(), "Pick a card number: ");
   EXPECT_EQ(input, "4");
   
   delete v;
}

