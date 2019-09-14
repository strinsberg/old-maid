#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

TEST(DeckTests, new_default_deck_and_size) {
    Deck d;
    EXPECT_EQ(d.size(), 52);
}


TEST(DeckTests, deck_with_2_packs) {
    Deck d(2);

    Card const* ah = d.getCard(0);

    EXPECT_EQ(ah->getValue(), 1);
    EXPECT_EQ(ah->getSuit(), Suit::HEART);
}


TEST(DeckTest, get_card_and_default_deck_order) {
    Deck d;

    Card const* ah = d.getCard(0);
    Card const* as = d.getCard(13);
    Card const* ad = d.getCard(26);
    Card const* ac = d.getCard(39);

    EXPECT_EQ(ah->getValue(), 1);
    EXPECT_EQ(ah->getSuit(), Suit::HEART);
    EXPECT_EQ(as->getValue(), 1);
    EXPECT_EQ(as->getSuit(), Suit::SPADE);
    EXPECT_EQ(ad->getValue(), 1);
    EXPECT_EQ(ad->getSuit(), Suit::DIAMOND);
    EXPECT_EQ(ac->getValue(), 1);
    EXPECT_EQ(ac->getSuit(), Suit::CLUB);
}


TEST(DeckTest, get_card_out_of_range) {
    Deck d;
    EXPECT_THROW(d.getCard(-1), std::out_of_range);
    EXPECT_THROW(d.getCard(60), std::out_of_range);
}
