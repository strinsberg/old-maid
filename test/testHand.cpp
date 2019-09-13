#include <gtest/gtest.h>
#include "Hand.h"


TEST(HandTests, constructor_and_size_empty) {
    Hand h;
    EXPECT_EQ(h.size(), 0);
}
