#pragma once
#include "../core/core.hpp"
string convert_to_binary(ull n, int length = 0) {
    string ret = bitset<64>(n).to_string();
    int digit = __builtin_clzll(n);
    ret = ret.substr(min(digit, 64 - length));
    return ret;
}
