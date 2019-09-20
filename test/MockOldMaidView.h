#ifndef MOCK_OLD_MAID_VIEW_H
#define MOCK_OLD_MAID_VIEW_H


#include <gmock/gmock.h>
#include <iostream>
#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "Card.h"


class MockOldMaidView : public OldMaidView {
 public:
    explicit MockOldMaidView(
        std::vector<Player*>* players, std::ostream& out = std::cout)
        : OldMaidView(players, out) {}
    virtual ~MockOldMaidView() {}

    MOCK_CONST_METHOD1(turnInfo, void(int currentPlayer));
    MOCK_CONST_METHOD0(pickCard, void());
    MOCK_CONST_METHOD2(result, void(Card const* card, bool matched));
    MOCK_CONST_METHOD3(result, void(Card const* c, bool m, Card const* o));
    MOCK_CONST_METHOD1(endRound, void(int loser));
};

#endif
