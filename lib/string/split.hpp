#pragma once
#include "../core/core.hpp"
[[nodiscard]] vector<string> split(const string &s, const string &spliter) {
    vector<string> ret;
    int head = 0;
    ll fi;
    while((fi = s.find(spliter, head)) < string::npos) {
        ret.emplace_back(s.substr(head, fi - head));
        head = fi + spliter.size();
    }
    ret.emplace_back(s.substr(head));
    return ret;
}
