#pragma once
#include "../core/core.hpp"

// from: https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
istream &operator>>(istream &is, __int128 &v) {
    string s;
    is >> s;
    v = 0;
    for(char c : s) {
        if(isdigit(c)) v = v * 10 + (c - '0');
    }
    if(s[0] == '-') v *= -1;
    return is;
}

ostream &operator<<(ostream &os, const __int128 &v) {
    if(!ostream::sentry(os)) return os;
    char buf[64];
    char *d = end(buf);
    __uint128_t tmp = (v < 0 ? -v : v);

    do {
        d--;
        *d = char(tmp % 10 + '0');
        tmp /= 10;
    } while(tmp);
    if(v < 0) {
        d--;
        *d = '-';
    }
    int len = end(buf) - d;
    if(os.rdbuf()->sputn(d, len) != len) {
        os.setstate(ios_base::badbit);
    }
    return os;
}
