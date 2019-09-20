#include <gtest/gtest.h>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "OldMaidView.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"


TEST(TestOldMaidView, turn_info) {
    std::stringstream ss;

    Player steve("Steve");
    Player comp("Comp1");
    std::vector<Player*> players{&steve, &comp};

    Card* c1 = new Card(1, Suit::HEART);
    Card* c2 = new Card(2, Suit::HEART);
    Card* c3 = new Card(1, Suit::SPADE);
    Card* c4 = new Card(2, Suit::SPADE);

    steve.getHand()->addCard(c1);
    steve.getHand()->addCard(c2);
    comp.getHand()->addCard(c3);
    comp.getHand()->addCard(c4);

    OldMaidView view(&players, ss);

    view.turnInfo(0);

    EXPECT_EQ("=== Steve's Turn ===\n\n"
              "-- Hand Sizes --\n"
              "Steve: 2\n"
              "Comp1: 2\n\n"
              "-- Your Cards --\n"
              "AH 2H \n\n", ss.str());
}


TEST(TestOldMaidView, pick_card) {
    std::stringstream ss;
    OldMaidView view(nullptr, ss);

    view.pickCard();
    EXPECT_EQ("Choose card: ", ss.str());
}


TEST(TestOldMaidView, result_not_a_match) {
    std::stringstream ss;
    OldMaidView view(nullptr, ss);

    const Card c(12, Suit::HEART);
    view.result(&c, false);

    EXPECT_EQ("\nCard Chosen: QH\n\n"
              "** Not a Match **\n"
              "The QH was added to your hand\n\n"
              "=== Turn Over ===\n\n", ss.str());
}


TEST(TestOldMaidView, result_a_match) {
    std::stringstream ss;
    OldMaidView view(nullptr, ss);

    const Card c1(12, Suit::HEART);
    const Card c2(12, Suit::SPADE);
    view.result(&c1, true, &c2);

    EXPECT_EQ("\nCard Chosen: QH\n\n"
              "** It's a Match **\n"
              "The QS was removed from your hand\n\n"
              "=== Turn Over ===\n\n", ss.str());
}


TEST(TestOldMaidView, end_round) {
    std::stringstream ss;
    Player steve("Steve");
    std::vector<Player*> players{&steve};
    OldMaidView view(&players, ss);

    view.endRound(0);
    EXPECT_EQ("=== Round Over ===\n\nOld Maid: Steve\n", ss.str());
}


TEST(TestOldMaidView, end_round_throws) {
    std::stringstream ss;
    Player steve("Steve");
    std::vector<Player*> players{&steve};
    OldMaidView view(&players, ss);

    EXPECT_THROW(view.endRound(20), std::out_of_range);
    EXPECT_THROW(view.endRound(-1), std::out_of_range);
}
