#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Input.h"


TEST(InputTests, get_int) {
    std::stringstream ss("4");
    Input in(ss);

    EXPECT_EQ(in.getInt(), 4);
}


TEST(InputTests, get_int_throws) {
    std::stringstream ss("help");
    Input in(ss);

    EXPECT_THROW(in.getInt(), std::invalid_argument);
}


TEST(InputTests, get_string) {
    std::stringstream ss("steve rules");
    Input in(ss);

    EXPECT_EQ(in.getString(), "steve");
}


TEST(InputTests, wait) {
    std::stringstream ss;
    Input in(ss);
    
    in.wait();
    EXPECT_EQ("", ss.str());
}

