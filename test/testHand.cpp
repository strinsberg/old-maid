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
    h.addCard(new Card(2, Suit::DIAMOND));
    h.addCard(new Card(2, Suit::CLUB));

    h.sortBy(false, true);

    EXPECT_EQ(h.getCard(0)->getSuit(), Suit::HEART);
    EXPECT_EQ(h.getCard(1)->getSuit(), Suit::HEART);
    EXPECT_EQ(h.getCard(2)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(3)->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.getCard(4)->getSuit(), Suit::DIAMOND);
    EXPECT_EQ(h.getCard(5)->getSuit(), Suit::CLUB);
}


TEST(HandTests, sort_by_value_and_suit) {
    Hand h;

    h.addCard(new Card(3, Suit::SPADE));
    h.addCard(new Card(4, Suit::HEART));
    h.addCard(new Card(1, Suit::SPADE));
    h.addCard(new Card(2, Suit::HEART));
    h.addCard(new Card(2, Suit::DIAMOND));
    h.addCard(new Card(2, Suit::CLUB));

    h.sortBy(true, true);


    EXPECT_EQ(2, h.getCard(0)->getValue());
    EXPECT_EQ(4, h.getCard(1)->getValue());
    EXPECT_EQ(1, h.getCard(2)->getValue());
    EXPECT_EQ(3, h.getCard(3)->getValue());
    EXPECT_EQ(2, h.getCard(4)->getValue());
    EXPECT_EQ(2, h.getCard(5)->getValue());

    EXPECT_EQ(Suit::HEART, h.getCard(0)->getSuit());
    EXPECT_EQ(Suit::HEART, h.getCard(1)->getSuit());
    EXPECT_EQ(Suit::SPADE, h.getCard(2)->getSuit());
    EXPECT_EQ(Suit::SPADE, h.getCard(3)->getSuit());
    EXPECT_EQ(Suit::DIAMOND, h.getCard(4)->getSuit());
    EXPECT_EQ(Suit::CLUB, h.getCard(5)->getSuit());
}

TEST(HandTests, to_string) {
    Hand h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    EXPECT_EQ(h.toString(), "2S, 10H, KD, AC");
}
