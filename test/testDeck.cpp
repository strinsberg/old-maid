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


TEST(TestDeck, find_card_assume_default_order) {
    Deck d;
    
    int pos = d.findCard(1, Suit::HEART);
    
    EXPECT_EQ(pos, 0);
}


TEST(TestDeck, find_card_not_present) {
    Deck d;
    
    int pos = d.findCard(15, Suit::HEART);
    
    EXPECT_EQ(pos, -1);
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

TEST(DeckTest, shuffle) {
    Deck d;

    d.shuffle();
    Card const* ah = d.getCard(0);
    Card const* as = d.getCard(13);
    Card const* ad = d.getCard(26);
    Card const* ac = d.getCard(39);

    // if one of the cards is not the ace expected before the shuffle
    // then we will considered the deck shuffled. It is impossible to
    // know what will be in any position if we are randomizing it. So we
    // try a few things we know should be in those positions if the suffle
    // did not work.
    EXPECT_TRUE(ah->getValue() != 1 && ah->getSuit() != Suit::HEART
        || as->getValue() != 1 && as->getSuit() != Suit::SPADE
        || ad->getValue() != 1 && ad->getSuit() != Suit::DIAMOND
        || ac->getValue() != 1 && ac->getSuit() != Suit::CLUB);
}


TEST(DeckTest, deal_4_hands_of_4) {
    Deck d;

    std::vector<Hand*> hands = d.deal(4, 4);

    for (auto h : hands) {
        EXPECT_EQ(h->size(), 4);
    }

    Card const* c0 = hands[0]->getCard(0);
    Card const* c1 = hands[0]->getCard(1);
    Card const* c2 = hands[0]->getCard(2);
    Card const* c3 = hands[0]->getCard(3);

    EXPECT_EQ(c0->getValue(), 13);
    EXPECT_EQ(c0->getSuit(), Suit::CLUB);
    EXPECT_EQ(c1->getValue(), 9);
    EXPECT_EQ(c1->getSuit(), Suit::CLUB);
    EXPECT_EQ(c2->getValue(), 5);
    EXPECT_EQ(c2->getSuit(), Suit::CLUB);
    EXPECT_EQ(c3->getValue(), 1);
    EXPECT_EQ(c3->getSuit(), Suit::CLUB);

    for (auto h : hands)
        delete h;
}


TEST(DeckTest, deal_3_whole_deck) {
    Deck d;

    std::vector<Hand*> hands = d.deal(3);

    EXPECT_EQ(hands[0]->size(), 18);
    EXPECT_EQ(hands[1]->size(), 17);
    EXPECT_EQ(hands[2]->size(), 17);

    for (auto h : hands)
        delete h;
}
