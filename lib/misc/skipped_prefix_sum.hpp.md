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
    \ 3 \"lib/misc/skipped_prefix_sum.hpp\"\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u3092\u547C\u3073\u51FA\u3057\u305F\u5F8C\u306Bval\u306E\u5024\u3092\u5909\
    \u66F4\u3057\u3066\u3082\u69CB\u308F\u306A\u3044\u304C\u3001\u5909\u66F4\u306F\
    \u53CD\u6620\u3055\u308C\u306A\u3044\n// STEP \u500B\u3068\u3070\u3057\u306E\u7D2F\
    \u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\ntemplate <class T> class SkippedPrefixSum\
    \ {\n    vector<T> prefix_sum;\n    const int STEP;\n    const int SIZE;\n\n \
    \   void init_prefix_sum(const vector<T> &val) {\n        prefix_sum.resize(val.size()\
    \ + 1);\n        for(int i = 1; i <= val.size(); i++) {\n            if(i < STEP)\
    \ {\n                prefix_sum[i] = val[i - 1];\n            }\n            else\
    \ {\n                prefix_sum[i] = prefix_sum[i - STEP] + val[i - 1];\n    \
    \        }\n        }\n        return;\n    }\n\npublic:\n    SkippedPrefixSum()\
    \ {}\n    SkippedPrefixSum(const vector<T> &val, int step = 1) : STEP(step), SIZE(val.size())\
    \ {\n        assert(STEP > 0);\n        init_prefix_sum(val);\n    }\n\n    //\
    \ \u26A0\uFE0F \u9589\u533A\u9593 [l, r] \u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\
    \u610F\n    // return sum[l, r] := val[l] + val[l+STEP] + ... + val[r]\n    //\
    \ O(1)\n    T get(int l, int r) const {\n        assert(0 <= l && l < SIZE);\n\
    \        assert(0 <= r && r < SIZE);\n        assert((r - l) % STEP == 0);\n \
    \       if(l > r) return T(0);\n        int l_ = max(0, l - (STEP - 1));\n   \
    \     int r_ = r + 1;\n        return prefix_sum[r_] - prefix_sum[l_];\n    }\n\
    \n    // from \u304B\u3089 STEP \u523B\u307F\u3067 num \u500B\u53D6\u3063\u305F\
    \u548C\u3092\u8FD4\u3059\n    T get2(int from, int num) const { return get(from,\
    \ from + (num - 1) * STEP); }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u3092\u547C\u3073\u51FA\u3057\u305F\u5F8C\u306Bval\u306E\u5024\u3092\
    \u5909\u66F4\u3057\u3066\u3082\u69CB\u308F\u306A\u3044\u304C\u3001\u5909\u66F4\
    \u306F\u53CD\u6620\u3055\u308C\u306A\u3044\n// STEP \u500B\u3068\u3070\u3057\u306E\
    \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\ntemplate <class T> class SkippedPrefixSum\
    \ {\n    vector<T> prefix_sum;\n    const int STEP;\n    const int SIZE;\n\n \
    \   void init_prefix_sum(const vector<T> &val) {\n        prefix_sum.resize(val.size()\
    \ + 1);\n        for(int i = 1; i <= val.size(); i++) {\n            if(i < STEP)\
    \ {\n                prefix_sum[i] = val[i - 1];\n            }\n            else\
    \ {\n                prefix_sum[i] = prefix_sum[i - STEP] + val[i - 1];\n    \
    \        }\n        }\n        return;\n    }\n\npublic:\n    SkippedPrefixSum()\
    \ {}\n    SkippedPrefixSum(const vector<T> &val, int step = 1) : STEP(step), SIZE(val.size())\
    \ {\n        assert(STEP > 0);\n        init_prefix_sum(val);\n    }\n\n    //\
    \ \u26A0\uFE0F \u9589\u533A\u9593 [l, r] \u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\
    \u610F\n    // return sum[l, r] := val[l] + val[l+STEP] + ... + val[r]\n    //\
    \ O(1)\n    T get(int l, int r) const {\n        assert(0 <= l && l < SIZE);\n\
    \        assert(0 <= r && r < SIZE);\n        assert((r - l) % STEP == 0);\n \
    \       if(l > r) return T(0);\n        int l_ = max(0, l - (STEP - 1));\n   \
    \     int r_ = r + 1;\n        return prefix_sum[r_] - prefix_sum[l_];\n    }\n\
    \n    // from \u304B\u3089 STEP \u523B\u307F\u3067 num \u500B\u53D6\u3063\u305F\
    \u548C\u3092\u8FD4\u3059\n    T get2(int from, int num) const { return get(from,\
    \ from + (num - 1) * STEP); }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/misc/skipped_prefix_sum.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/skipped_prefix_sum.hpp
layout: document
redirect_from:
- /library/lib/misc/skipped_prefix_sum.hpp
- /library/lib/misc/skipped_prefix_sum.hpp.html
title: lib/misc/skipped_prefix_sum.hpp
---
