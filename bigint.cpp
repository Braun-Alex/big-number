#include "bigint.h"

void bigInt::setHex(const std::string& bigNumber) {
    size_t size = bigNumber.size();
    blocks.clear();
    blocks.reserve(size);
    for (const auto& hexDigit: bigNumber) {
        blocks.emplace_back(
                std::bitset<4>(
                        std::stoi(
                                std::string(1, hexDigit), nullptr, 16)));
    }
}

std::string bigInt::getHex() const {
    std::string hexNumber;
    hexNumber.reserve(blocks.size());
    for (const auto& bitset: blocks) {
        hexNumber.push_back(table[bitset.to_ulong()]);
    }
    return hexNumber;
}

void bigInt::INV() {
    for (auto& bitset: this->blocks) {
        bitset.flip();
    }
}

void bigInt::XOR(const bigInt& otherNumber) {
    size_t size = blocks.size(),
           otherSize = otherNumber.blocks.size();
    bigInt result, copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        result.blocks.reserve(otherSize);
        for (int i = 0; i < otherSize; i++) {
            result.blocks.push_back(copy.blocks[i] ^ otherNumber.blocks[i]);
        }
    } else if (size == otherSize) {
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(blocks[i] ^ otherNumber.blocks[i]);
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(copy.blocks[i] ^ blocks[i]);
        }
    }
    *this = result;
}