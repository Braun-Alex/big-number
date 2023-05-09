#include "bigint.h"
#include <iostream>

int main() {
    bigInt value;
    value.setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
    bigInt anotherValue;
    anotherValue.setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
    value.ADD(anotherValue);
    std::cout << value.getHex();
    return 0;
}