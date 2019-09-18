#ifndef MOCK_DECK_H
#define MOCK_DECK_H


#include <gmock/gmock.h>
#include <vector>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Suit.h"


class MockDeck : public Deck {
 public:
    explicit MockDeck() : Deck() {}
    virtual ~MockDeck();

    MOCK_METHOD2(findCard, int(int value, Suit suit));
    MOCK_METHOD1(getCard, Card const*(int i));
    MOCK_METHOD2(deal, std::vector<Hand*>(int hands, int cards));
    MOCK_METHOD0(shuffle, void());
    MOCK_METHOD0(size, int());
};

#endif
