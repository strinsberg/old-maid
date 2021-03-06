#ifndef MOCK_PLAYER_H
#define MOCK_PLAYER_H


#include <gmock/gmock.h>
#include <string>
#include "Player.h"
#include "CardCollection.h"


class MockPlayer : public Player {
 public:
    explicit MockPlayer() : Player("Test Player") {}
    virtual ~MockPlayer() {}

    MOCK_METHOD0(getName, std::string());
    MOCK_METHOD0(getHand, CardCollection*());
    MOCK_METHOD0(getScore, int());
    MOCK_METHOD1(updateScore, int(int amount));
    MOCK_METHOD1(setHand, void(CardCollection* hand));
    MOCK_METHOD2(sortHand, void(bool byVal, bool bySuit));
};

#endif
