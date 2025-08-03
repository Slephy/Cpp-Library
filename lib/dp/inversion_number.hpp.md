---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/binary_indexed_tree/bit.hpp
    title: lib/binary_indexed_tree/bit.hpp
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
    \ 3 \"lib/binary_indexed_tree/bit.hpp\"\n// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\
    \u30FC\u30B9\u306F 0-indexed \u534A\u958B\u533A\u9593\ntemplate <class T> class\
    \ BIT {\nprivate:\n    int n;\n    vector<T> bit;\n\npublic:\n    // constructor\n\
    \    BIT(int n) : n(n), bit(n + 1, 0) {}\n\n    // O(logN)\n    void add(int index,\
    \ T value) {\n        index++;\n        assert(1 <= index && index <= n);\n  \
    \      for(int i = index; i <= n; i += (i & (-i))) {\n            bit[i] += value;\n\
    \        }\n        return;\n    }\n\n    // O(logN)\n    void set(int index,\
    \ T value) {\n        add(index, value - get(index));\n        return;\n    }\n\
    \n    // O(logN)\n    // return value of val[index]\n    T get(int index) const\
    \ { return sum(index, index + 1); }\n\n    // O(logN)\n    // return sum of val[l,\
    \ r)\n    T sum(int l, int r) const { return _sum(r) - _sum(l); }\n    T sum(int\
    \ l) const { return sum(l, n); }\n\n    size_t size() const { return n; }\n\n\
    \    friend ostream &operator<<(ostream &o, const BIT<T> &bit) {\n        for(int\
    \ i = 0; i < bit.n; i++) {\n            o << bit.sum(i, i + 1) << (i + 1 == bit.n\
    \ ? ELM_SEP : \" \");\n        }\n        return o;\n    }\n\nprivate:\n    //\
    \ O(logN)\n    // return sum of val[0, index)\n    T _sum(int index) const {\n\
    \        T res = 0;\n        assert(0 <= index && index <= n);\n        for(int\
    \ i = index; i > 0; i -= (i & (-i))) {\n            res += bit[i];\n        }\n\
    \        return res;\n    }\n};\n#line 4 \"lib/dp/inversion_number.hpp\"\n// \u4E88\
    \u3081\u914D\u5217\u3092\u5727\u7E2E\u3059\u308B\u3001\u3082\u3057\u304F\u306F\
    \u8981\u7D20\u306E\u6700\u5927\u5024\u3092\u5165\u529B\u3059\u308B\u5FC5\u8981\
    \u3042\u308A\ntemplate <class T> ll inversion_number(const vector<T> &v, ll val_MAX\
    \ = -1) {\n    ll ret = 0;\n    assert(val_MAX >= -1);\n    val_MAX = (val_MAX\
    \ == -1) ? v.size() : val_MAX + 1;\n    BIT<ll> bit(val_MAX);\n    for(int i =\
    \ 0; i < v.size(); i++) {\n        ret += bit.sum(v[i] + 1, val_MAX);\n      \
    \  bit.add(v[i], 1);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../binary_indexed_tree/bit.hpp\"\n#include \"../core/core.hpp\"\
    \n// \u4E88\u3081\u914D\u5217\u3092\u5727\u7E2E\u3059\u308B\u3001\u3082\u3057\u304F\
    \u306F\u8981\u7D20\u306E\u6700\u5927\u5024\u3092\u5165\u529B\u3059\u308B\u5FC5\
    \u8981\u3042\u308A\ntemplate <class T> ll inversion_number(const vector<T> &v,\
    \ ll val_MAX = -1) {\n    ll ret = 0;\n    assert(val_MAX >= -1);\n    val_MAX\
    \ = (val_MAX == -1) ? v.size() : val_MAX + 1;\n    BIT<ll> bit(val_MAX);\n   \
    \ for(int i = 0; i < v.size(); i++) {\n        ret += bit.sum(v[i] + 1, val_MAX);\n\
    \        bit.add(v[i], 1);\n    }\n    return ret;\n}\n"
  dependsOn:
  - lib/binary_indexed_tree/bit.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/inversion_number.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/inversion_number.hpp
layout: document
redirect_from:
- /library/lib/dp/inversion_number.hpp
- /library/lib/dp/inversion_number.hpp.html
title: lib/dp/inversion_number.hpp
---
