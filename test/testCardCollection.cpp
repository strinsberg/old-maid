#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
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


TEST(CardCollectionTests, find_card) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    int pos = h.findCard(10, Suit::HEART);

    EXPECT_EQ(pos, 1);
}




TEST(CardCollectionTests, find_card_not_present) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    int pos = h.findCard(5, Suit::HEART);

    EXPECT_EQ(pos, -1);
}


TEST(CardCollectionTests, get_card) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    Card const* c = h.getCard(0);

    EXPECT_EQ(c->getValue(), 2);
    EXPECT_EQ(c->getSuit(), Suit::SPADE);
}


TEST(CardCollectionTests, get_card_out_of_range) {
    CardCollection h;

    EXPECT_THROW(h.getCard(10), std::out_of_range);
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


TEST(CardCollection, take_all_cards) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    std::vector<int> idxs{1, 2};

    std::vector<Card const*> taken = h.takeAllCards(idxs);

    EXPECT_EQ(2, taken.size());
    EXPECT_EQ(2, h.size());

    EXPECT_EQ(13, taken.at(0)->getValue());
    EXPECT_EQ(10, taken.at(1)->getValue());

    EXPECT_EQ(2, h.getCard(0)->getValue());
    EXPECT_EQ(1, h.getCard(1)->getValue());

    for (auto c : taken)
        delete c;
}


TEST(CardCollectionTests, take_card_out_of_range) {
    CardCollection h;

    EXPECT_THROW(h.takeCard(10), std::out_of_range);
}


TEST(CardCollectionTests, iterators) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    EXPECT_EQ(2, (*h.begin())->getValue());
    EXPECT_EQ(10, (*(h.begin() + 1))->getValue());
    EXPECT_EQ(13, (*(h.begin() + 2))->getValue());
    EXPECT_EQ(1, (*(h.begin() + 3))->getValue());
}


TEST(CardCollectionTests, to_string) {
    CardCollection h;

    h.addCard(new Card(2, Suit::SPADE));
    h.addCard(new Card(10, Suit::HEART));
    h.addCard(new Card(13, Suit::DIAMOND));
    h.addCard(new Card(1, Suit::CLUB));

    EXPECT_EQ(h.toString(), "2S, 10H, KD, AC");
}
