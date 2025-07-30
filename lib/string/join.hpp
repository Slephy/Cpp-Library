#pragma once
#include "../core/core.hpp"
[[nodiscard]] string join(const vector<string> &v, const string &joiner) {
    string ret = "";
    for(int i = 0; i < v.size(); i++) {
        ret += v[i];
        if(i != v.size() - 1) ret += joiner;
    }
    return ret;
}
