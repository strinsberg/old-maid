#ifndef MOCK_VIEW_H
#define MOCK_VIEW_H


#include <gmock/gmock.h>
#include <vector>
#include "View.h"
#include "Player.h"


class MockView : public View {
 public:
    explicit MockView() {}
    virtual ~MockView() {}

    MOCK_METHOD0(welcome, void());
    MOCK_METHOD0(getName, void());
    MOCK_METHOD0(askNumAI, void());
    MOCK_METHOD1(beginRound, void(std::vector<Player*> players));
    MOCK_METHOD1(gameStatus, void(std::vector<Player*> players));
    MOCK_METHOD2(endRound, void(std::vector<Player*> players, int winner));
};

#endif
