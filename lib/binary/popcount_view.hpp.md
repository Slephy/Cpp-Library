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
    \ 3 \"lib/binary/popcount_view.hpp\"\n// \u9577\u3055\u304C length \u3067\u3001\
    1 \u306E\u6570\u304C count \u500B\u306E\u30D3\u30C3\u30C8\u5217\u306B\u5BFE\u5FDC\
    \u3059\u308B\u6574\u6570\u3092\u5217\u6319\u3059\u308B\nclass PopcountView {\n\
    public:\n    PopcountView(size_t length, size_t count)\n        : begin_((1LL\
    \ << count) - 1), end_(numeric_limits<ll>::max()), inf((1LL << length)) {\n  \
    \      assert(count <= length);\n    }\n\n    class Iterator {\n    public:\n\
    \        Iterator(ll value, ll inf) : value(value), inf(inf) {}\n        ll& operator*()\
    \ { return value; }\n        Iterator& operator++() {\n            if(value ==\
    \ 0) {\n                value = numeric_limits<ll>::max();\n                return\
    \ *this;\n            }\n            else {\n                ll x = value & -value,\
    \ y = value + x;\n                value = ((value & ~y) / x >> 1) | y;\n     \
    \           if(value >= inf) value = numeric_limits<ll>::max();\n            \
    \    return *this;\n            }\n        }\n        bool operator==(const Iterator&\
    \ other) const { return value == other.value; }\n        bool operator!=(const\
    \ Iterator& other) const { return !(*this == other); }\n\n    private:\n     \
    \   ll value, inf;\n    };\n\n    Iterator begin() const { return Iterator(begin_,\
    \ inf); }\n    Iterator end() const { return Iterator(end_, inf); }\n\nprivate:\n\
    \    ll begin_, end_, inf;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u9577\u3055\u304C length\
    \ \u3067\u30011 \u306E\u6570\u304C count \u500B\u306E\u30D3\u30C3\u30C8\u5217\u306B\
    \u5BFE\u5FDC\u3059\u308B\u6574\u6570\u3092\u5217\u6319\u3059\u308B\nclass PopcountView\
    \ {\npublic:\n    PopcountView(size_t length, size_t count)\n        : begin_((1LL\
    \ << count) - 1), end_(numeric_limits<ll>::max()), inf((1LL << length)) {\n  \
    \      assert(count <= length);\n    }\n\n    class Iterator {\n    public:\n\
    \        Iterator(ll value, ll inf) : value(value), inf(inf) {}\n        ll& operator*()\
    \ { return value; }\n        Iterator& operator++() {\n            if(value ==\
    \ 0) {\n                value = numeric_limits<ll>::max();\n                return\
    \ *this;\n            }\n            else {\n                ll x = value & -value,\
    \ y = value + x;\n                value = ((value & ~y) / x >> 1) | y;\n     \
    \           if(value >= inf) value = numeric_limits<ll>::max();\n            \
    \    return *this;\n            }\n        }\n        bool operator==(const Iterator&\
    \ other) const { return value == other.value; }\n        bool operator!=(const\
    \ Iterator& other) const { return !(*this == other); }\n\n    private:\n     \
    \   ll value, inf;\n    };\n\n    Iterator begin() const { return Iterator(begin_,\
    \ inf); }\n    Iterator end() const { return Iterator(end_, inf); }\n\nprivate:\n\
    \    ll begin_, end_, inf;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/binary/popcount_view.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/binary/popcount_view.hpp
layout: document
redirect_from:
- /library/lib/binary/popcount_view.hpp
- /library/lib/binary/popcount_view.hpp.html
title: lib/binary/popcount_view.hpp
---
