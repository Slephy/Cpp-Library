#pragma once

using namespace std;
#include <atcoder/modint>
#include <iostream>
namespace atcoder {
template <int m> istream &operator>>(istream &i, static_modint<m, (void *)nullptr> &a) {
    long long v;
    i >> v;
    a = v;
    return i;
}
template <int m> istream &operator>>(istream &i, dynamic_modint<m> &a) {
    long long v;
    i >> v;
    a = v;
    return i;
}
template <int m> ostream &operator<<(ostream &o, const static_modint<m, (void *)nullptr> &a) { return o << a.val(); }
template <int m> ostream &operator<<(ostream &o, const dynamic_modint<m> &a) { return o << a.val(); }
}  // namespace atcoder
