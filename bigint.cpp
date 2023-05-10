#include "bigint.h"
#include <iostream>

bigInt::bigInt() {}

bigInt::bigInt(std::bitset<4> bitset) {
    blocks.push_back(bitset);
}

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
    for (auto& bitset: blocks) {
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
    *this = std::move(result);
}

void bigInt::OR(const bigInt& otherNumber) {
    size_t size = blocks.size(),
            otherSize = otherNumber.blocks.size();
    bigInt result, copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        result.blocks.reserve(otherSize);
        for (int i = 0; i < otherSize; i++) {
            result.blocks.push_back(copy.blocks[i] | otherNumber.blocks[i]);
        }
    } else if (size == otherSize) {
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(blocks[i] | otherNumber.blocks[i]);
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(copy.blocks[i] | blocks[i]);
        }
    }
    *this = std::move(result);
}

void bigInt::AND(const bigInt& otherNumber) {
    size_t size = blocks.size(),
            otherSize = otherNumber.blocks.size();
    bigInt result, copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        result.blocks.reserve(otherSize);
        for (int i = 0; i < otherSize; i++) {
            result.blocks.push_back(copy.blocks[i] & otherNumber.blocks[i]);
        }
    } else if (size == otherSize) {
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(blocks[i] & otherNumber.blocks[i]);
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        result.blocks.reserve(size);
        for (int i = 0; i < size; i++) {
            result.blocks.push_back(copy.blocks[i] & blocks[i]);
        }
    }
    *this = std::move(result);
}

void bigInt::shiftR(size_t n) {
    size_t size = blocks.size();
    std::deque<bool> binaryNumber;
    binaryNumber.resize(size * 4);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            binaryNumber[i * 4 + j] = blocks[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        binaryNumber.pop_front();
    }
    for (int i = 0; i < n; i++) {
        binaryNumber.push_back(false);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            blocks[i][j] = binaryNumber[i * 4 + j];
        }
    }
}

void bigInt::shiftL(size_t n) {
    size_t size = blocks.size();
    std::deque<bool> binaryNumber;
    binaryNumber.resize(size * 4);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            binaryNumber[i * 4 + j] = blocks[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        binaryNumber.pop_back();
    }
    for (int i = 0; i < n; i++) {
        binaryNumber.push_front(false);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            blocks[i][j] = binaryNumber[i * 4 + j];
        }
    }
}

bool bigInt::operator==(const bigInt& otherNumber) const {
    size_t size = blocks.size(),
            otherSize = otherNumber.blocks.size();
    bigInt copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        for (int i = 0; i < otherSize; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != otherNumber.blocks[i][j]) {
                    return false;
                }
            }
        }
    } else if (size == otherSize) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (blocks[i][j] != otherNumber.blocks[i][j]) {
                    return false;
                }
            }
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != blocks[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool bigInt::operator>(const bigInt& otherNumber) const {
    size_t size = blocks.size(),
            otherSize = otherNumber.blocks.size();
    bigInt copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        for (int i = 0; i < otherSize; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != otherNumber.blocks[i][j]) {
                    return copy.blocks[i][j] > otherNumber.blocks[i][j];
                }
            }
        }
    } else if (size == otherSize) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (blocks[i][j] != otherNumber.blocks[i][j]) {
                    return blocks[i][j] > otherNumber.blocks[i][j];
                }
            }
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != blocks[i][j]) {
                    return copy.blocks[i][j] > blocks[i][j];
                }
            }
        }
    }
    return false;
}

bool bigInt::operator<(const bigInt& otherNumber) const {
    size_t size = blocks.size(),
            otherSize = otherNumber.blocks.size();
    bigInt copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        for (int i = 0; i < otherSize; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != otherNumber.blocks[i][j]) {
                    return copy.blocks[i][j] < otherNumber.blocks[i][j];
                }
            }
        }
    } else if (size == otherSize) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (blocks[i][j] != otherNumber.blocks[i][j]) {
                    return blocks[i][j] < otherNumber.blocks[i][j];
                }
            }
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (copy.blocks[i][j] != blocks[i][j]) {
                    return copy.blocks[i][j] < blocks[i][j];
                }
            }
        }
    }
    return false;
}

void bigInt::ADD(const bigInt& otherNumber) {
    bool carry = false;
    size_t size = blocks.size(),
           otherSize = otherNumber.blocks.size();
    std::vector<std::bitset<4>> result;
    bigInt copy;
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + getHex());
        result.resize(otherSize);
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = copy.blocks[i][j] ^ otherNumber.blocks[i][j] ^ carry;
                carry = copy.blocks[i][j] & otherNumber.blocks[i][j] |
                        copy.blocks[i][j] & carry |
                        otherNumber.blocks[i][j] & carry;
            }
        }
    } else if (size == otherSize) {
        result.resize(size);
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = blocks[i][j] ^ otherNumber.blocks[i][j] ^ carry;
                carry = blocks[i][j] & otherNumber.blocks[i][j] |
                        blocks[i][j] & carry |
                        otherNumber.blocks[i][j] & carry;
            }
        }
    } else {
        copy.setHex(std::string(size - otherSize, '0') + otherNumber.getHex());
        result.resize(size);
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = copy.blocks[i][j] ^ blocks[i][j] ^ carry;
                carry = copy.blocks[i][j] & blocks[i][j] |
                        copy.blocks[i][j] & carry |
                        blocks[i][j] & carry;
            }
        }
    }
    if (carry) {
        result.insert(result.begin(), std::bitset<4>("0001"));
    }
    blocks = std::move(result);
}

void bigInt::SUB(const bigInt& otherNumber) {
    if (otherNumber > *this) {
        throw std::invalid_argument("Negative result of subtracting numbers");
    }
    bigInt complement = otherNumber;
    complement.INV();
    bigInt one;
    one.setHex("1");
    complement.ADD(one);
    ADD(complement);
    blocks.erase(blocks.begin());
}

bigInt bigInt::MOD(const bigInt& number) const {
    bigInt copy, remainder = *this, divider = number;
    size_t size = remainder.blocks.size(),
           otherSize = divider.blocks.size();
    if (size < otherSize) {
        copy.setHex(std::string(otherSize - size, '0') + remainder.getHex());
        remainder = std::move(copy);
    } else if (size > otherSize) {
        copy.setHex(std::string(size - otherSize, '0') + divider.getHex());
        divider = std::move(copy);
    }
    if (remainder < divider) {
        return remainder;
    } else if (remainder == divider) {
        remainder.setHex("0");
        return remainder;
    }
    while (remainder > divider) {
        remainder.SUB(divider);
    }
    if (remainder == divider) {
        remainder.setHex("0");
    }
    std::bitset<4> zeroBitset("0000");
    decltype(remainder.blocks.begin()) iterator;
    for (iterator = remainder.blocks.begin(); iterator != remainder.blocks.end();
    ++iterator) {
        if (*iterator != zeroBitset) {
            break;
        }
    }
    remainder.blocks.erase(remainder.blocks.begin(), iterator);
    return remainder;
}