#ifndef MOCK_OLD_MAID_VIEW_H
#define MOCK_OLD_MAID_VIEW_H


#include <gmock/gmock.h>
#include "OldMaidView.h"
#include "Card.h"


class MockOldMaidView : public OldMaidView {
 public:
    explicit MockOldMaidView(std::vector<Player*>* players, std::ostream& out)
        : OldMaidView(players, out) {}
    virtual ~MockOldMaidView() {}
    
    MOCK_METHOD1(playerInfo, void(int currentPlayer));
    MOCK_METHOD0(pickCard, void());
    MOCK_METHOD2(result, void(Card const* card, bool matched));
    MOCK_METHOD1(endGame, void(int loser));
};

#endif
