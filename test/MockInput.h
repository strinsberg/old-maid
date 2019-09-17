#ifndef MOCK_INPUT_H
#define MOCK_INPUT_H


#include <gmock/gmock.h>
#include "Input.h"


class MockInput : public Input {
 public:
    MOCK_METHOD(int, getInt, (), (override));
    MOCK_METHOD(int, getString, (), (override));
};

#endif
