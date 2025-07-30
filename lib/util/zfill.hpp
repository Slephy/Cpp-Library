#pragma once
#include "../core/core.hpp"
// val の先頭を 0 で埋めて min_length 文字にする
// min_length が val の桁数より小さい場合はそのまま返す
string zfill(ll val, int min_length = 0) {
    string s = to_string(val);
    int length = s.size();
    string ret = string(max(0, min_length - length), '0') + s;
    return ret;
}
