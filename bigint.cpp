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