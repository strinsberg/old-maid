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

    MOCK_CONST_METHOD2(findCard, int(int value, Suit suit));
    MOCK_METHOD1(takeCard, Card*(int idx));
    MOCK_METHOD0(size, int());
    MOCK_METHOD0(toString, std::string());
};

#endif
