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


TEST(HandTests, DISABLED_find_card) {
    Hand h;
    Card const* c = new Card(2, Suit::SPADE);

    h.addCard(c);
    int i = h.matchCard(2, Suit::SPADE);
    int j = h.matchCard(2);

    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 0);
    EXPECT_EQ(h.size(), 1);
}

TEST(HandTests, DISABLED_find_card_not_there) {
    Hand h;
    Card const* c = new Card(2, Suit::SPADE);

    h.addCard(c);
    int i = h.matchCard(2, Suit::HEART);
    int j = h.matchCard(3);

    EXPECT_EQ(i, -1);
    EXPECT_EQ(j, -1);
    EXPECT_EQ(h.size(), 1);
}


TEST(HandTests, get_card) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.getCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.size(), 1);
}


TEST(HandTests, get_card_out_of_range) {
    Hand h;

    EXPECT_THROW(h.getCard(10), std::out_of_range);
}

TEST(HandTests, take_card) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.takeCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.size(), 0);

    delete c;
}

TEST(HandTests, take_card_out_of_range) {
    Hand h;

    EXPECT_THROW(h.takeCard(10), std::out_of_range);
}


TEST(HandTests, sort_by_value) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(3, Suit::HEART));
    h.addCard(new Card(1, Suit::SPADE));
    h.addCard(new Card(2, Suit::HEART));

    h.sortBy(true, false);

    EXPECT_EQ(h.getCard(0)->getValue(), 1);
    EXPECT_EQ(h.getCard(1)->getValue(), 2);
    EXPECT_EQ(h.getCard(2)->getValue(), 2);
    EXPECT_EQ(h.getCard(3)->getValue(), 3);
}


TEST(HandTests, sort_by_suit) {
    Hand h;

    h.addCard(new Card(3, Suit::SPADE));
    h.addCard(new Card(4, Suit::HEART));
    h.addCard(new Card(1, Suit::SPADE));
    h.addCard(new Card(2, Suit::HEART));

    h.sortBy(false, true);

    EXPECT_EQ(h.getCard(0)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(1)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(2)->getSuit(), Suit::HEART);
    EXPECT_EQ(h.getCard(3)->getSuit(), Suit::HEART);
}


TEST(HandTests, sort_by_value_and_suit) {
    Hand h;

    h.addCard(new Card(3, Suit::SPADE));
    h.addCard(new Card(4, Suit::HEART));
    h.addCard(new Card(1, Suit::SPADE));
    h.addCard(new Card(2, Suit::HEART));

    h.sortBy(true, false);

    EXPECT_EQ(h.getCard(0)->getValue(), 1);
    EXPECT_EQ(h.getCard(1)->getValue(), 5);
    EXPECT_EQ(h.getCard(2)->getValue(), 2);
    EXPECT_EQ(h.getCard(3)->getValue(), 4);

    EXPECT_EQ(h.getCard(0)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(1)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(2)->getSuit(), Suit::HEART);
    EXPECT_EQ(h.getCard(3)->getSuit(), Suit::HEART);
}

TEST(HandTests, to_string) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    EXPECT_EQ(h.toString(), "2S, 10H, KD, AC");
}
