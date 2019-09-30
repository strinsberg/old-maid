#ifndef MOCK_VIEW_H
#define MOCK_VIEW_H


#include <vector>
#include "View.h"
#include "Player.h"


class MockView : public View {
 public:
    explicit MockView() {}
    virtual ~MockView() {}

    Mock_Method0(welcome, void());
    Mock_Method0(getName, void());
    Mock_Method0(askNumAI, void());
    Mock_Method1(beginRound, void(std::vector<Player*> players));
    Mock_Method2(endRound, void(std::vector<Player*> players, int winner));
};

#endif
