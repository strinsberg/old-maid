#ifndef MOCK_INPUT_H
#define MOCK_INPUT_H


#include <gmock/gmock.h>
#include <string>
#include "Input.h"


class MockInput : public Input {
 public:
    explicit MockInput() {}
    virtual ~MockInput() {}

    MOCK_METHOD0(getInt, int());
    MOCK_METHOD0(getString, std::string());
};

#endif
