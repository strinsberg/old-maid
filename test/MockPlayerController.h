#ifndef MOCK_PLAYER_CONTROLLER_H
#define MOCK_PLAYER_CONTROLLER_H


#include <gmock/gmock.h>
#include <vector>
#include "Player.h"
#include "Deck.h"


class MockPlayerController : public PlayerController {
 public:
    explicit MockPlayerController() : PlayerController(nullptr, nullptr) {}
    virtual ~MockPlayerController() {}

    MOCK_METHOD2(takeTurn, bool(Deck* deck, std::vector<Player*> players));
    MOCK_METHOD0(getPlayer, Player*());
    MOCK_METHOD0(isOut, bool());
};

#endif
