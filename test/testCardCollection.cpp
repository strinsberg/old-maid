#include <gtest/gtest.h>
#include <stdexcept>
#include "CardCollection.h"
#include "Card.h"
#include "Suit.h"


TEST(CardCollectionTests, constructor_and_size_empty) {
    CardCollection h;
    EXPECT_EQ(h.size(), 0);
}


TEST(CardCollectionTests, add_card) {
    CardCollection h;
    h.addCard(new Card(2, Suit::SPADE));
    EXPECT_EQ(h.size(), 1);
}

// Not ready yet
TEST(CardCollectionTests, DISABLED_find_card_assume_default_order) {
    CardCollection c;

    int pos = c.findCard(1, Suit::HEART);

    EXPECT_EQ(pos, 0);
}

// Not ready yet
TEST(CardCollectionTests, DISABLED_find_card_not_present) {
    CardCollection c;

    int pos = c.findCard(15, Suit::HEART);

    EXPECT_EQ(pos, -1);
}


TEST(CardCollectionTests, take_card) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.takeCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
    EXPECT_EQ(h.size(), 0);

    delete c;
}

TEST(CardCollectionTests, take_card_out_of_range) {
    CardCollection h;

    EXPECT_THROW(h.takeCard(10), std::out_of_range);
}


TEST(CardCollectionTests, DISABLED_iterators) {
    //Nothing Yet
}


TEST(CardCollectionTests, to_string) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    EXPECT_EQ(h.toString(), "2S, 10H, KD, AC");
}
