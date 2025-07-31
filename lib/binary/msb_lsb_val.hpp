#pragma once
#include "../core/core.hpp"
// 1の最上位ビットのみが立った整数を返す
// ⚠️ n = 0 のときは 0 を返す
// get_msb(0) == 0
// get_msb(0b1010) == 0b1000
ull get_msb(ull n) {
    if(n == 0) return 0;
    else return 1ULL << (63 - __builtin_clzll(n));
}

// 1の最下位ビットのみが立った整数を返す
// ⚠️ n = 0 のときは 0 を返す
// get_lsb(0) == 0
// get_lsb(0b1010) == 0b0010
ull get_lsb(ull n) { return n & ~(n - 1); }
