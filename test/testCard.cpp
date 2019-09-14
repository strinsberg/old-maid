#include <gtest/gtest.h>
#include <stdexcept>
#include "Card.h"
#include "Suit.h"


TEST(CardTests, test_card) {
    Card card(2, Suit::SPADE);
    EXPECT_EQ(card.getValue(), 2);
    EXPECT_EQ(card.getSuit(), Suit::SPADE);
}


TEST(CardTests, test_card_value_out_of_range) {
    EXPECT_THROW(Card(0, Suit::SPADE), std::invalid_argument);
    EXPECT_THROW(Card(14, Suit::SPADE), std::invalid_argument);
}


TEST(CardTests, test_to_string_letter_cards) {
    Card cj(11, Suit::HEART);
    Card cq(12, Suit::SPADE);
    Card ck(13, Suit::CLUB);
    Card ca(1, Suit::DIAMOND);

    EXPECT_EQ(cj.toString(), "JH");
    EXPECT_EQ(cq.toString(), "QS");
    EXPECT_EQ(ck.toString(), "KC");
    EXPECT_EQ(ca.toString(), "AD");
}


TEST(CardTests, test_to_string_number_cards) {
    Card c2(2, Suit::SPADE);
    Card c10(10, Suit::HEART);

    EXPECT_EQ(c2.toString(), "2S");
    EXPECT_EQ(c10.toString(), "10H");
}
