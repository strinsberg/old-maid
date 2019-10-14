#ifndef MOCK_DECK_H
#define MOCK_DECK_H


#include <gmock/gmock.h>
#include <vector>
#include "Deck.h"
#include "CardCollection.h"
#include "Card.h"


class MockDeck : public Deck {
 public:
    explicit MockDeck() {}
    virtual ~MockDeck() {}

    MOCK_METHOD0(takeTop, Card*());
    MOCK_METHOD0(getCards, CardCollection*());
    MOCK_METHOD2(deal, std::vector<CardCollection*>(int hands, int cards));
    MOCK_METHOD0(shuffle, void());
};

#endif
