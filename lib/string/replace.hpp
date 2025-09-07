#pragma once
#include "../core/core.hpp"
#include "./z-algo.hpp"

namespace slephy {
// O(max(|s|, |ret|))
[[nodiscard]] string replace(const string &s, const string &from, const string &to) {
    if(from.empty()) return s;
    string tmp = from + char(128) + s;
    vector<int> z = z_algorithm(tmp);

    string ret;
    int n = (int)s.size(), m = (int)from.size();
    for(int i = 0; i < n;) {
        if(z[i + m + 1] >= m) {
            ret += to;
            i += m;
        }
        else {
            ret += s[i];
            i++;
        }
    }
    return ret;
}
};  // namespace slephy
