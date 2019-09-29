#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "OldMaidView.h"
#include "Player.h"

using testing::internal::CaptureStdout;
using testing::internal::GetCapturedStdout;


TEST(TestOldMaidView, welcome) {
    CaptureStdout();
    OldMaidView view;

    view.welcome();
    std::string output = GetCapturedStdout();
    EXPECT_EQ("==== Old Maid ====\n\n", output);
}


TEST(TestOldMaidView, get_name) {
    CaptureStdout();
    OldMaidView view;

    view.getName();
    std::string output = GetCapturedStdout();
    EXPECT_EQ("Enter name: ", output);
}


TEST(TestOldMaidView, get_num_AI) {
    CaptureStdout();
    OldMaidView view;

    view.askNumAI();
    std::string output = GetCapturedStdout();
    EXPECT_EQ("How many opponents would you like (2-4): ",
        output);
}


TEST(TestOldMaidView, begin_round) {
    CaptureStdout();
    OldMaidView view;

    std::vector<Player*> players;

    view.beginRound(players);
    std::string output = GetCapturedStdout();
    EXPECT_EQ("Some player Info", output);
}


TEST(TestOldMaidView, end_round) {
    CaptureStdout();
    OldMaidView view;

    std::vector<Player*> players;

    view.endRound(players, 0);
    std::string output = GetCapturedStdout();
    EXPECT_EQ("Some player Info", output);
}

