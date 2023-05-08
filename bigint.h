#pragma once
#include <vector>

#ifndef WIN64
using block = std::vector<int32_t>;
#elif
using blockNumber = std::vector<int64_t>;
#endif

class bigInt {
public:
private:
    blockNumber block = blockNumber {};
};