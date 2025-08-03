#pragma once
#include "../core/core.hpp"
// 1の最上位ビットが何桁目かを返す
// ⚠️ n = 0 のときは -1 を返す
// get_msb(0) == -1
// get_msb(0b1010) == 3
ll get_msb(ull n) {
    if(n == 0) return -1;
    else return (63 - __builtin_clzll(n));
}

// 1の最下位ビットが何桁目かを返す
// ⚠️ n = 0 のときは -1 を返す
// get_lsb(0) == -1
// get_lsb(0b1010) == 1
ll get_lsb(ull n) {
    if(n == 0) return -1;
    else return __builtin_ctzll(n & ~(n - 1));
}
