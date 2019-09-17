#ifndef MOCK_OLD_MAID_VIEW_H
#define MOCK_OLD_MAID_VIEW_H


#include <gmock/gmock.h>
#include "OldMaidView.h"
#include "Card.h"


class MockOldMaidView : public OldMaidView {
 public:
    MOCK_METHOD(void, playerInfo, (int currentPlayer), (const, override));
    MOCK_METHOD(void, pickCard, (), (const, override));
    MOCK_METHOD(void, result, (Card const* card, bool matched), (const, override));
    MOCK_METHOD(void, endGame, (int loser), (const, override));
};

#endif
