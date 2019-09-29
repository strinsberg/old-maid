#ifndef MOCK_CARD_COLLECTION_H
#define MOCK_CARD_COLLECTION_H


#include <string>
#include "CardCollection.h"


class MockCardCollection : public CardCollection {
 public:
    explicit MockCardCollection() : CardCollection() {}
    virtual ~MockCardCollection() {}

    MOCK_METHOD0(size, int());
    MOCK_METHOD0(toString, std::string());
};

#endif
