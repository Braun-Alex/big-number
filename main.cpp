#include "bigint.h"
#include <iostream>

int main() {
    bigInt value;
    value.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
    bigInt anotherValue;
    anotherValue.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
    value.XOR(anotherValue);
    std::cout << value.getHex();
    return 0;
}