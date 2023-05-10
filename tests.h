#pragma once
#include "bigint.h"
#include <gtest/gtest.h>

class InitializingFixture: public testing::TestWithParam<bigInt> {
protected:
    void SetUp() override;
};