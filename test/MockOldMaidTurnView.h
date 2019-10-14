#ifndef MOCK_OM_TURN_VIEW_H
#define MOCK_OM_TURN_VIEW_H


#include <gmock/gmock.h>
#include <string>
#include <vector>
#include "OldMaidTurnView.h"
#include "Player.h"
#include "Card.h"


class MockOldMaidTurnView : public OldMaidTurnView {
 public:
    explicit MockOldMaidTurnView() : OldMaidTurnView(NULL) {}
    virtual ~MockOldMaidTurnView() {}

    MOCK_METHOD0(turnInfo, void());
    MOCK_METHOD1(takeAction, void(Player* left));
    MOCK_METHOD1(badInput, void(std::string message));
    MOCK_METHOD2(turnResult, void(Card const* card, bool success));
    MOCK_METHOD0(wait, void());
};

#endif
