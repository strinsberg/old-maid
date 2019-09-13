#include <gtest/gtest.h>
#include "Card.h"
#include "Suit.h"


TEST(CardTests, test_card) {
    Card const* card = new Card(2, Suit::SPADE);
    EXPECT_EQ(card->getValue(), 2);
    EXPECT_EQ(card->getSuit(), Suit::SPADE);
    delete card;
}
