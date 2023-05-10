#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <deque>
#include <stdexcept>

class bigInt {
public:
    bigInt();
    explicit bigInt(std::bitset<4> bitset);
    void setHex(const std::string& hexNumber);
    std::string getHex() const;
    void INV();
    void XOR(const bigInt& otherNumber);
    void OR(const bigInt& otherNumber);
    void AND(const bigInt& otherNumber);
    void shiftL(size_t n);
    void shiftR(size_t n);
    bool operator==(const bigInt& otherNumber) const;
    bool operator>(const bigInt& otherNumber) const;
    bool operator<(const bigInt& otherNumber) const;
    void ADD(const bigInt& otherNumber);
    void SUB(const bigInt& otherNumber);
    bigInt MOD(const bigInt& number) const;
private:
    std::vector<std::bitset<4>> blocks;
    inline static const std::string table = "0123456789abcdef";
};