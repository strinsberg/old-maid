#include <gtest/gtest.h>
#include <stdexcept>
#include "Hand.h"
#include "Card.h"
#include "Suit.h"


TEST(HandTests, constructor_and_size_empty) {
    Hand h;
    EXPECT_EQ(h.size(), 0);
}


TEST(HandTests, add_card) {
    Hand h;
    h.addCard(new Card(2, Suit::SPADE));
    EXPECT_EQ(h.size(), 1);
}


TEST(HandTests, find_card) {
    Hand h;
    Card const* c = new Card(2, Suit::SPADE);
    h.addCard(c);
    int i = h.findCard(c);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(h.size(), 0);
}


TEST(HandTests, DISABLED_get_card) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.getCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.size(), 0);
}


TEST(HandTests, DISABLED_take_card) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.takeCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.size(), 0);

    delete c;
}
