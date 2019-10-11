#ifndef MOCK_CARD_COLLECTION_H
#define MOCK_CARD_COLLECTION_H


#include <gmock/gmock.h>
#include <string>
#include "CardCollection.h"
#include "Suit.h"
#include "Card.h"


class MockCardCollection : public CardCollection {
 public:
    explicit MockCardCollection() : CardCollection() {}
    virtual ~MockCardCollection() {}

    MOCK_METHOD1(addCard, void(Card const* card));
    MOCK_CONST_METHOD2(findCard, int(int value, Suit suit));
    MOCK_METHOD1(takeCard, Card const*(int idx));
    MOCK_METHOD1(takeAllCards, std::vector<Card const*>(std::vector<int> idxs));
    MOCK_METHOD0(size, int());
    MOCK_METHOD0(toString, std::string());
};

#endif
