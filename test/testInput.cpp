#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "Input.h"
#include "OldMaidView.h"


TEST(InputTests, get_int) {
    std::stringstream ss("4");
    Input in(ss);
    
    EXPECT_EQ(in.getInt(), 4);
}


TEST(InputTests, get_string) {
    std::stringstream ss("steve rules");
    Input in(ss);
    
    EXPECT_EQ(in.getString(), "steve");
}

