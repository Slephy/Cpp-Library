---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/core/core.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst int INF\
    \ = (int)1e9 + 1001010;\nconst ll llINF = (long long)4e18 + 22000020;\nconst string\
    \ endn = \"\\n\";\ntemplate <class T> inline auto vector2(size_t i, size_t j,\
    \ const T &init = T()) {\n    return vector(i, vector<T>(j, init));\n}\nconst\
    \ string ELM_SEP = \" \", VEC_SEP = endn;\ntemplate <class T> istream &operator>>(istream\
    \ &i, vector<T> &A) {\n    for(auto &I : A) i >> I;\n    return i;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &o, const vector<T> &A) {\n    int sz\
    \ = A.size();\n    for(const auto &I : A) o << I << (--sz ? ELM_SEP : \"\");\n\
    \    return o;\n}\ntemplate <class T> ostream &operator<<(ostream &o, const vector<vector<T>>\
    \ &A) {\n    int sz = A.size();\n    for(const auto &I : A) o << I << (--sz ?\
    \ VEC_SEP : \"\");\n    return o;\n}\ntemplate <class T> vector<T> &operator++(vector<T>\
    \ &A, int) {\n    for(auto &I : A) I++;\n    return A;\n}\ntemplate <class T>\
    \ vector<T> &operator--(vector<T> &A, int) {\n    for(auto &I : A) I--;\n    return\
    \ A;\n}\ntemplate <class T, class U> bool chmax(T &a, const U &b) { return ((a\
    \ < b) ? (a = b, true) : false); }\ntemplate <class T, class U> bool chmin(T &a,\
    \ const U &b) { return ((a > b) ? (a = b, true) : false); }\nll floor_div(ll a,\
    \ ll b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0) ? a / b : (a + 1)\
    \ / b - 1;\n}\nll ceil_div(ll a, ll b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a > 0) ? (a - 1) / b + 1 : a / b;\n}\nbool check_bit(ull val, ull digit) {\
    \ return (val >> digit) & 1; }\n#ifdef DEBUG\n#include <cpp-dump/cpp-dump.hpp>\n\
    #define dump(...) cpp_dump(__VA_ARGS__)\nnamespace cp = cpp_dump;\nstruct InitCppDump\
    \ {\n    InitCppDump() {\n        if(!isatty(fileno(stderr))) CPP_DUMP_SET_OPTION(es_style,\
    \ cpp_dump::types::es_style_t::no_es);\n        CPP_DUMP_SET_OPTION(log_label_func,\
    \ cp::log_label::line());\n        CPP_DUMP_SET_OPTION(max_iteration_count, 30);\n\
    \    }\n} init_cpp_dump;\n#else\n#define dump(...)\n#endif\n// ====================\
    \ \u3053\u3053\u307E\u3067\u30C6\u30F3\u30D7\u30EC ====================\n#line\
    \ 3 \"lib/modint/modint61.hpp\"\n\nstruct modint61 {\n    using mint = modint61;\n\
    \    using i64 = long long;\n    using i128 = __int128_t;\n    using u64 = unsigned\
    \ long long;\n    using u128 = __uint128_t;\n\n    const static i64 m = (i64)(1LL\
    \ << 61) - 1;\n\n    static constexpr i64 mod() { return m; }\n    static mint\
    \ raw(i64 v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\
    \    modint61() : _v(0) {}\n    modint61(i64 v) {\n        if(v >= 0) _v = calc_mod(v);\n\
    \        else if(v >= -m) _v = v + m;\n        else {\n            i64 x = v %\
    \ m;\n            if(x < 0) x += m;\n            _v = x;\n        }\n    }\n \
    \   // modint61(bool v) { _v = ((unsigned int)(v) % umod());\n    i64 val() const\
    \ { return _v; }\n    mint& operator++() {\n        _v++;\n        if(_v == m)\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if(_v\
    \ == 0) _v = m;\n        _v--;\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
    \    }\n    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n    mint& operator+=(const mint& rhs) {\n    \
    \    _v += rhs._v;\n        if(_v >= m) _v -= m;\n        return *this;\n    }\n\
    \    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n        if(_v\
    \ >= umod()) _v += umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        u128 z = _v;\n        z *= rhs._v;\n        _v = calc_mod(z);\n\
    \        return *this;\n    }\n    mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inv(); }\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint() - *this; }\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1LL;\n    \
    \    while(n) {\n            if(n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       assert(_v);\n        return pow(m - 2);\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend istream&\
    \ operator>>(istream& i, mint& a) {\n        long long v;\n        i >> v;\n \
    \       a = v;\n        return i;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.val(); }\n\nprivate:\n    u64 calc_mod(u128\
    \ x) {\n        u64 res = (x >> 61) + (x & m);\n        if(res >= m) res -= m;\n\
    \        return res;\n    }\n    u64 _v;\n    static constexpr u64 umod() { return\
    \ m; }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\nstruct modint61 {\n    using\
    \ mint = modint61;\n    using i64 = long long;\n    using i128 = __int128_t;\n\
    \    using u64 = unsigned long long;\n    using u128 = __uint128_t;\n\n    const\
    \ static i64 m = (i64)(1LL << 61) - 1;\n\n    static constexpr i64 mod() { return\
    \ m; }\n    static mint raw(i64 v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n    modint61() : _v(0) {}\n    modint61(i64 v) {\n   \
    \     if(v >= 0) _v = calc_mod(v);\n        else if(v >= -m) _v = v + m;\n   \
    \     else {\n            i64 x = v % m;\n            if(x < 0) x += m;\n    \
    \        _v = x;\n        }\n    }\n    // modint61(bool v) { _v = ((unsigned\
    \ int)(v) % umod());\n    i64 val() const { return _v; }\n    mint& operator++()\
    \ {\n        _v++;\n        if(_v == m) _v = 0;\n        return *this;\n    }\n\
    \    mint& operator--() {\n        if(_v == 0) _v = m;\n        _v--;\n      \
    \  return *this;\n    }\n    mint operator++(int) {\n        mint result = *this;\n\
    \        ++*this;\n        return result;\n    }\n    mint operator--(int) {\n\
    \        mint result = *this;\n        --*this;\n        return result;\n    }\n\
    \    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n        if(_v\
    \ >= m) _v -= m;\n        return *this;\n    }\n    mint& operator-=(const mint&\
    \ rhs) {\n        _v -= rhs._v;\n        if(_v >= umod()) _v += umod();\n    \
    \    return *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        u128\
    \ z = _v;\n        z *= rhs._v;\n        _v = calc_mod(z);\n        return *this;\n\
    \    }\n    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv();\
    \ }\n    mint operator+() const { return *this; }\n    mint operator-() const\
    \ { return mint() - *this; }\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        mint x = *this, r = 1LL;\n        while(n) {\n            if(n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        assert(_v);\n        return\
    \ pow(m - 2);\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs)\
    \ { return mint(lhs) += rhs; }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend istream&\
    \ operator>>(istream& i, mint& a) {\n        long long v;\n        i >> v;\n \
    \       a = v;\n        return i;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.val(); }\n\nprivate:\n    u64 calc_mod(u128\
    \ x) {\n        u64 res = (x >> 61) + (x & m);\n        if(res >= m) res -= m;\n\
    \        return res;\n    }\n    u64 _v;\n    static constexpr u64 umod() { return\
    \ m; }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/modint/modint61.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/modint/modint61.hpp
layout: document
redirect_from:
- /library/lib/modint/modint61.hpp
- /library/lib/modint/modint61.hpp.html
title: lib/modint/modint61.hpp
---
