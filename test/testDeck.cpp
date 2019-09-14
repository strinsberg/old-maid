#include <gtest/gtest.h>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

TEST(DeckTests, new_default_deck_and_size) {
    Deck d;
    EXPECT_EQ(d.size(), 52);
}
