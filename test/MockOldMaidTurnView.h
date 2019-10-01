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
    explicit MockOldMaidTurnView() {}
    virtual ~MockOldMaidTurnView() {}

    MOCK_METHOD1(turnInfo, void(std::vector<Player*> players));
    MOCK_METHOD1(playerInfo, void(Player* player));
    MOCK_METHOD0(takeAction, void());
    MOCK_METHOD1(badInput, void(std::string message));
    MOCK_METHOD2(turnResult, void(Card const* card, bool success));
};

#endif
