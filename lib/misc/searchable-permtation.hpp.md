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
    \ 3 \"lib/misc/searchable-permtation.hpp\"\n\n// \u9006\u5F15\u304D\u53EF\u80FD\
    \u306A\u9806\u5217\n// 0 \u304B\u3089 n-1 \u307E\u3067\u306E\u9806\u5217\u3092\
    \u683C\u7D0D\u3059\u308B\nclass SearchablePermutation{\nprivate:\n    vector<int>\
    \ val;\n    vector<int> idx; // idx[v] := (val\u5185\u3067\u306Ev\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9)\n    size_t n; // \u9806\u5217\u306E\u8981\u7D20\u6570\
    \n\n\npublic:\n    SearchablePermutation(const vector<int> &val) : val(val), idx(val.size(),\
    \ -1), n(val.size()){\n        vector<bool> emplaced(n, false);\n        for(int\
    \ i = 0; i < val.size(); i++){\n            assert(0 <= val[i] && val[i] < n);\n\
    \            assert(!emplaced[val[i]]); // \u8981\u7D20\u304C\u91CD\u8907\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\n            idx[val[i]] = i;\n         \
    \   emplaced[val[i]] = true;\n        }\n    }\n    // {0, 1, 2, ... , n-1} \u3067\
    \u521D\u671F\u5316\n    SearchablePermutation(size_t n) : val(n), idx(n), n(n)\
    \ {\n        iota(val.begin(), val.end(), 0);\n        iota(idx.begin(), idx.end(),\
    \ 0);\n    }\n\n    // O(1)\n    int size() const {\n        return n;\n    }\n\
    \n    // O(1)\n    int get_idx(int val) const {\n        return idx[val];\n  \
    \  }\n\n    // O(1)\n    int operator[](size_t idx) const {\n        return val[idx];\n\
    \    }\n\n    // O(1)\n    void swap_by_value(int val1, int val2){\n        int\
    \ idx1 = get_idx(val1);\n        int idx2 = get_idx(val2);\n        std::swap(val[idx1],\
    \ val[idx2]);\n        std::swap(idx[val1], idx[val2]);\n    }\n\n    // O(1)\n\
    \    void swap_by_index(int idx1, int idx2){\n        int val1 = val[idx1];\n\
    \        int val2 = val[idx2];\n        std::swap(val[idx1], val[idx2]);\n   \
    \     std::swap(idx[val1], idx[val2]);\n    }\n\n    friend ostream& operator\
    \ <<(ostream &o, const SearchablePermutation &sv){o << sv.val; return o;}\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// \u9006\u5F15\u304D\u53EF\
    \u80FD\u306A\u9806\u5217\n// 0 \u304B\u3089 n-1 \u307E\u3067\u306E\u9806\u5217\
    \u3092\u683C\u7D0D\u3059\u308B\nclass SearchablePermutation{\nprivate:\n    vector<int>\
    \ val;\n    vector<int> idx; // idx[v] := (val\u5185\u3067\u306Ev\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9)\n    size_t n; // \u9806\u5217\u306E\u8981\u7D20\u6570\
    \n\n\npublic:\n    SearchablePermutation(const vector<int> &val) : val(val), idx(val.size(),\
    \ -1), n(val.size()){\n        vector<bool> emplaced(n, false);\n        for(int\
    \ i = 0; i < val.size(); i++){\n            assert(0 <= val[i] && val[i] < n);\n\
    \            assert(!emplaced[val[i]]); // \u8981\u7D20\u304C\u91CD\u8907\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\n            idx[val[i]] = i;\n         \
    \   emplaced[val[i]] = true;\n        }\n    }\n    // {0, 1, 2, ... , n-1} \u3067\
    \u521D\u671F\u5316\n    SearchablePermutation(size_t n) : val(n), idx(n), n(n)\
    \ {\n        iota(val.begin(), val.end(), 0);\n        iota(idx.begin(), idx.end(),\
    \ 0);\n    }\n\n    // O(1)\n    int size() const {\n        return n;\n    }\n\
    \n    // O(1)\n    int get_idx(int val) const {\n        return idx[val];\n  \
    \  }\n\n    // O(1)\n    int operator[](size_t idx) const {\n        return val[idx];\n\
    \    }\n\n    // O(1)\n    void swap_by_value(int val1, int val2){\n        int\
    \ idx1 = get_idx(val1);\n        int idx2 = get_idx(val2);\n        std::swap(val[idx1],\
    \ val[idx2]);\n        std::swap(idx[val1], idx[val2]);\n    }\n\n    // O(1)\n\
    \    void swap_by_index(int idx1, int idx2){\n        int val1 = val[idx1];\n\
    \        int val2 = val[idx2];\n        std::swap(val[idx1], val[idx2]);\n   \
    \     std::swap(idx[val1], idx[val2]);\n    }\n\n    friend ostream& operator\
    \ <<(ostream &o, const SearchablePermutation &sv){o << sv.val; return o;}\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/misc/searchable-permtation.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/searchable-permtation.hpp
layout: document
redirect_from:
- /library/lib/misc/searchable-permtation.hpp
- /library/lib/misc/searchable-permtation.hpp.html
title: lib/misc/searchable-permtation.hpp
---
