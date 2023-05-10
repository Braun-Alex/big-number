#pragma once
#include "bigint.h"
#include <gtest/gtest.h>

class InitializingFixture: public testing::TestWithParam<std::string> {
protected:
    void SetUp() override;
    std::string actualHexNumber;
    bigInt bigNumber;
};

class InvOperationFixture: public testing::TestWithParam<std::string> {
protected:
    void SetUp() override;
    bigInt bigNumber;
};

class XorOperationFixture: public testing::
        TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt firstBigNumber, secondBigNumber, expectedResult;
};

class OrOperationFixture: public testing::
TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt firstBigNumber, secondBigNumber, expectedResult;
};

class AndOperationFixture: public testing::
TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt firstBigNumber, secondBigNumber, expectedResult;
};

class ShiftROperationFixture: public testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    void SetUp() override;
    std::string expectedResult;
    bigInt bigNumber;
};

class ShiftLOperationFixture: public testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    void SetUp() override;
    std::string expectedResult;
    bigInt bigNumber;
};

class AddOperationFixture: public testing::
TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt firstBigNumber, secondBigNumber, expectedResult;
};

class SubOperationFixture: public testing::
TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt firstBigNumber, secondBigNumber, expectedResult;
};

class ModOperationFixture: public testing::
TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    void SetUp() override;
    bigInt bigNumber, divider, expectedResult;
};