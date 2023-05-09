#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <deque>

class bigInt {
public:
    void setHex(const std::string& hexNumber);
    std::string getHex() const;
    void INV();
    void XOR(const bigInt& otherNumber);
    void OR(const bigInt& otherNumber);
    void AND(const bigInt& otherNumber);
    void shiftL(size_t n);
    void shiftR(size_t n);
    void ADD(const bigInt& otherNumber);
private:
    std::vector<std::bitset<4>> blocks;
    inline static const std::string table = "0123456789abcdef";
};