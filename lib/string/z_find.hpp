#pragma once
#include "../core/core.hpp"
#include "./z-algo.hpp"

// O(|s| + |t|)
size_t z_find(const string &s, const string &t, size_t pos = 0) {
    vector<int> z;
    string tmp = t + char(128) + s;
    z = move(z_algorithm(tmp));
    for(int i = pos; i < s.size(); i++) {
        if(z[i + t.size() + 1] == t.size()) return i;
    }
    return string::npos;
}
