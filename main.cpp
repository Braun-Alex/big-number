#include "bigint.h"
#include <iostream>

int main() {
    bigInt value;
    value.setHex("5072f028943e0fd5fab3273782de14b1011741bd0c5cd6ba6474330");
    std::cout << value.getHex();
    return 0;
}