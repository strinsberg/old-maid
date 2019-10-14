#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
#include "CardCollection.h"
#include "Deck.h"
#include "Card.h"


TEST(DeckTests, new_default_deck_and_size) {
    Deck d;
    EXPECT_EQ(d.getCards()->size(), 52);
}


TEST(DeckTests, deck_with_2_packs) {
    Deck d(2);

    Card const* ah = d.getCards()->getCard(0);

    EXPECT_EQ(d.getCards()->size(), 104);
    EXPECT_EQ(ah->getValue(), 1);
    EXPECT_EQ(ah->getSuit(), Suit::HEART);
}


TEST(DeckTests, take_top) {
    Deck d;

    Card const* top = d.takeTop();

    EXPECT_EQ(13, top->getValue());
    EXPECT_EQ(Suit::CLUB, top->getSuit());
    EXPECT_EQ(51, d.getCards()->size());

    delete top;
}


TEST(DeckTest, shuffle) {
    Deck d;

    d.shuffle();
    Card const* ah = d.getCards()->getCard(0);
    Card const* as = d.getCards()->getCard(13);
    Card const* ad = d.getCards()->getCard(26);
    Card const* ac = d.getCards()->getCard(39);

    // This may fail every once in a blue moon, but it checks to make sure that
    // if one of the aces is not in it's original position the deck is
    // considered shuffled. It is very unlikely after a shuffle that all 4
    // aces will still be where they started. Could easily add a few more cards
    // to make this more strict.
    EXPECT_TRUE((ah->getValue() != 1 && ah->getSuit() != Suit::HEART)
        || (as->getValue() != 1 && as->getSuit() != Suit::SPADE)
        || (ad->getValue() != 1 && ad->getSuit() != Suit::DIAMOND)
        || (ac->getValue() != 1 && ac->getSuit() != Suit::CLUB));
}


TEST(DeckTest, deal_4_hands_of_4) {
    Deck d;

    std::vector<CardCollection*> hands = d.deal(4, 4);

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

    std::vector<CardCollection*> hands = d.deal(3, 0);

    EXPECT_EQ(hands[0]->size(), 18);
    EXPECT_EQ(hands[1]->size(), 17);
    EXPECT_EQ(hands[2]->size(), 17);

    for (auto h : hands)
        delete h;
}
