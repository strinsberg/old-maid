#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "OldMaidRound.h"
#include "MockInput.h"
#include "MockOldMaidView.h"
#include "MockDeck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Suit.h"


TEST(OldMaidRoundTests, new_round) {
    OldMaidRound r(nullptr, nullptr, nullptr, nullptr);
}
