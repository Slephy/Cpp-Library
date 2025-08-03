#pragma once
#include "../core/core.hpp"
// 整数 n を 10 進数から k 進数に変換する
string base_10_to_k(ll n, int k, int size = -1) {
    assert(1 <= k && k <= 36);
    assert(n >= 0);
    assert(size >= -1);

    if(n == 0) return "0";

    string ret = "";
    while(n != 0) {
        int mod = n % k;
        if(mod < 10) ret += mod + '0';
        else ret += mod - 10 + 'A';
        n /= k;
    }

    if(size != -1) {
        assert(ret.size() <= size);
        int zeroNum = size - (int)ret.size();
        for(int i = 0; i < zeroNum; i++) ret.push_back('0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
