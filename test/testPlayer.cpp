#include <gtest/gtest.h>
#include "Player.h"
#include "CardCollection.h"
#include "Suit.h"

TEST(PlayerTests, new_player_get_name) {
    Player p("Steve");

    EXPECT_EQ(p.getName(), "Steve");
}


TEST(PlayerTests, set_hand_get_hand) {
    Player p("Steve");
    CardCollection* h = new CardCollection();

    p.setHand(h);

    EXPECT_EQ(p.getHand(), h);
    EXPECT_EQ(p.getHand()->size(), 0);
}


TEST(PlayerTest, update_get_score) {
    Player p("Steve");

    int score = p.updateScore(10);
    EXPECT_EQ(score, 10);
    EXPECT_EQ(p.getScore(), 10);

    score = p.updateScore(-25);
    EXPECT_EQ(score, -15);
    EXPECT_EQ(p.getScore(), -15);
}


TEST(PlayerTests, sort_hand_by_value) {
    Player p("Steve");

    CardCollection* hand = p.getHand();
    hand->addCard(new Card(2, Suit::HEART));
    hand->addCard(new Card(1, Suit::SPADE));
    hand->addCard(new Card(3, Suit::CLUB));
    hand->addCard(new Card(4, Suit::HEART));
    hand->addCard(new Card(2, Suit::DIAMOND));
    hand->addCard(new Card(5, Suit::SPADE));

    p.sortHand(true, false);

    EXPECT_EQ(1, hand->getCard(0)->getValue());
    EXPECT_EQ(2, hand->getCard(1)->getValue());
    EXPECT_EQ(2, hand->getCard(2)->getValue());
    EXPECT_EQ(3, hand->getCard(3)->getValue());
    EXPECT_EQ(4, hand->getCard(4)->getValue());
    EXPECT_EQ(5, hand->getCard(5)->getValue());
}


TEST(PlayerTests, sort_hand_by_suit) {
    Player p("Steve");

    CardCollection* hand = p.getHand();
    hand->addCard(new Card(2, Suit::HEART));
    hand->addCard(new Card(1, Suit::SPADE));
    hand->addCard(new Card(3, Suit::CLUB));
    hand->addCard(new Card(4, Suit::HEART));
    hand->addCard(new Card(2, Suit::DIAMOND));
    hand->addCard(new Card(5, Suit::SPADE));

    p.sortHand(false, true);

    EXPECT_EQ(Suit::HEART, hand->getCard(0)->getSuit());
    EXPECT_EQ(Suit::HEART, hand->getCard(1)->getSuit());
    EXPECT_EQ(Suit::SPADE, hand->getCard(2)->getSuit());
    EXPECT_EQ(Suit::SPADE, hand->getCard(3)->getSuit());
    EXPECT_EQ(Suit::DIAMOND, hand->getCard(4)->getSuit());
    EXPECT_EQ(Suit::CLUB, hand->getCard(5)->getSuit());
}


TEST(PlayerTests, sort_hand_by_both) {
    Player p("Steve");

    CardCollection* hand = p.getHand();
    hand->addCard(new Card(2, Suit::HEART));
    hand->addCard(new Card(1, Suit::SPADE));
    hand->addCard(new Card(3, Suit::CLUB));
    hand->addCard(new Card(4, Suit::HEART));
    hand->addCard(new Card(2, Suit::DIAMOND));
    hand->addCard(new Card(5, Suit::SPADE));

    p.sortHand(true, true);

    EXPECT_EQ(2, hand->getCard(0)->getValue());
    EXPECT_EQ(4, hand->getCard(1)->getValue());
    EXPECT_EQ(1, hand->getCard(2)->getValue());
    EXPECT_EQ(5, hand->getCard(3)->getValue());
    EXPECT_EQ(2, hand->getCard(4)->getValue());
    EXPECT_EQ(3, hand->getCard(5)->getValue());

    EXPECT_EQ(Suit::HEART, hand->getCard(0)->getSuit());
    EXPECT_EQ(Suit::HEART, hand->getCard(1)->getSuit());
    EXPECT_EQ(Suit::SPADE, hand->getCard(2)->getSuit());
    EXPECT_EQ(Suit::SPADE, hand->getCard(3)->getSuit());
    EXPECT_EQ(Suit::DIAMOND, hand->getCard(4)->getSuit());
    EXPECT_EQ(Suit::CLUB, hand->getCard(5)->getSuit());
}
