#include "bigint.h"
#include <iostream>

int main() {
    bigInt value;
    value.setHex("33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc");
    bigInt anotherValue;
    anotherValue.setHex("22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03");
    value.SUB(anotherValue);
    std::cout << value.getHex();
    return 0;
}