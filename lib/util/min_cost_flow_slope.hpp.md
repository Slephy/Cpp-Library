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
    \ 3 \"lib/util/min_cost_flow_slope.hpp\"\n// slope\u95A2\u6570\u306E\u8FD4\u308A\
    \u5024\u3092\u6271\u3046\u95A2\u6570\n// flow \u3060\u3051\u6D41\u3059\u305F\u3081\
    \u306E\u30B3\u30B9\u30C8\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059\n// slope \u306F\
    \ slope\u95A2\u6570\u306E\u8FD4\u308A\u5024\n// O(log(|slope|))\ntemplate <class\
    \ Cap, class Cost> Cost get_cost(const vector<pair<Cap, Cost>> &slope, Cap flow)\
    \ {\n    Cap flow_max = slope.back().first;\n    assert(0 <= flow && flow <= flow_max);\n\
    \n    // flow \u304C slope \u306E\u3069\u306E\u533A\u9593\u306B\u5165\u308B\u304B\
    \u3092\u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B\n    // slope[ub-1].first\
    \ <= flow < slope[ub].first\n    int ub =\n        upper_bound(slope.begin(),\
    \ slope.end(), pair<Cap, Cost>(flow, numeric_limits<Cost>::max())) - slope.begin();\n\
    \n    if(ub == slope.size()) {  // flow == flow_max\u306E\u3068\u304D\n      \
    \  return slope.back().second;\n    }\n\n    // \u7DDA\u5F62\u88DC\u9593\n   \
    \ const auto &[cap1, cost1] = slope[ub - 1];\n    const auto &[cap2, cost2] =\
    \ slope[ub];\n    Cost d = (cost2 - cost1) / (cap2 - cap1);\n    Cost cost = cost1\
    \ + d * (flow - cap1);\n    return cost;\n}\n\n\n// slope\u95A2\u6570\u306E\u8FD4\
    \u308A\u5024\uFF08\u6298\u7DDA\uFF09\u3092\u5C55\u958B\u3059\u308B\u95A2\u6570\
    \n// slope \u306F slope\u95A2\u6570\u306E\u8FD4\u308A\u5024\n// O(flow_max)\n\
    // \u26A0\uFE0F Cap \u306F\u6574\u6570\u578B\u3068\u3059\u308B\u3053\u3068\ntemplate\
    \ <class Cap, class Cost> [[nodiscard]] vector<Cost> expand_slope(const vector<pair<Cap,\
    \ Cost>> &slope) {\n    assert(!slope.empty());\n    ll flow_max = slope.back().first;\n\
    \    assert(flow_max < (ll)1e8);\n\n    vector<Cost> res;\n    res.reserve(flow_max\
    \ + 1);\n    int index = 0;\n    ll d;\n    for(int i = 0; i <= flow_max; i++)\
    \ {\n        if(i == slope[index].first) {  // slope\u306E\u533A\u9593\u306E\u7AEF\
    \u70B9\u306E\u3068\u304D\n            res.emplace_back(slope[index].second);\n\
    \n            if(index + 1 < slope.size()) {\n                const auto &[cap1,\
    \ cost1] = slope[index];\n                const auto &[cap2, cost2] = slope[index\
    \ + 1];\n                d = (cost2 - cost1) / (cap2 - cap1);\n              \
    \  index++;\n            }\n        }\n        else {  // slope\u306E\u533A\u9593\
    \u5185\u306E\u3068\u304D\n            res.emplace_back(res.back() + d);\n    \
    \    }\n    }\n\n    return res;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// slope\u95A2\u6570\u306E\u8FD4\
    \u308A\u5024\u3092\u6271\u3046\u95A2\u6570\n// flow \u3060\u3051\u6D41\u3059\u305F\
    \u3081\u306E\u30B3\u30B9\u30C8\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059\n// slope\
    \ \u306F slope\u95A2\u6570\u306E\u8FD4\u308A\u5024\n// O(log(|slope|))\ntemplate\
    \ <class Cap, class Cost> Cost get_cost(const vector<pair<Cap, Cost>> &slope,\
    \ Cap flow) {\n    Cap flow_max = slope.back().first;\n    assert(0 <= flow &&\
    \ flow <= flow_max);\n\n    // flow \u304C slope \u306E\u3069\u306E\u533A\u9593\
    \u306B\u5165\u308B\u304B\u3092\u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B\
    \n    // slope[ub-1].first <= flow < slope[ub].first\n    int ub =\n        upper_bound(slope.begin(),\
    \ slope.end(), pair<Cap, Cost>(flow, numeric_limits<Cost>::max())) - slope.begin();\n\
    \n    if(ub == slope.size()) {  // flow == flow_max\u306E\u3068\u304D\n      \
    \  return slope.back().second;\n    }\n\n    // \u7DDA\u5F62\u88DC\u9593\n   \
    \ const auto &[cap1, cost1] = slope[ub - 1];\n    const auto &[cap2, cost2] =\
    \ slope[ub];\n    Cost d = (cost2 - cost1) / (cap2 - cap1);\n    Cost cost = cost1\
    \ + d * (flow - cap1);\n    return cost;\n}\n\n\n// slope\u95A2\u6570\u306E\u8FD4\
    \u308A\u5024\uFF08\u6298\u7DDA\uFF09\u3092\u5C55\u958B\u3059\u308B\u95A2\u6570\
    \n// slope \u306F slope\u95A2\u6570\u306E\u8FD4\u308A\u5024\n// O(flow_max)\n\
    // \u26A0\uFE0F Cap \u306F\u6574\u6570\u578B\u3068\u3059\u308B\u3053\u3068\ntemplate\
    \ <class Cap, class Cost> [[nodiscard]] vector<Cost> expand_slope(const vector<pair<Cap,\
    \ Cost>> &slope) {\n    assert(!slope.empty());\n    ll flow_max = slope.back().first;\n\
    \    assert(flow_max < (ll)1e8);\n\n    vector<Cost> res;\n    res.reserve(flow_max\
    \ + 1);\n    int index = 0;\n    ll d;\n    for(int i = 0; i <= flow_max; i++)\
    \ {\n        if(i == slope[index].first) {  // slope\u306E\u533A\u9593\u306E\u7AEF\
    \u70B9\u306E\u3068\u304D\n            res.emplace_back(slope[index].second);\n\
    \n            if(index + 1 < slope.size()) {\n                const auto &[cap1,\
    \ cost1] = slope[index];\n                const auto &[cap2, cost2] = slope[index\
    \ + 1];\n                d = (cost2 - cost1) / (cap2 - cap1);\n              \
    \  index++;\n            }\n        }\n        else {  // slope\u306E\u533A\u9593\
    \u5185\u306E\u3068\u304D\n            res.emplace_back(res.back() + d);\n    \
    \    }\n    }\n\n    return res;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/min_cost_flow_slope.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/min_cost_flow_slope.hpp
layout: document
redirect_from:
- /library/lib/util/min_cost_flow_slope.hpp
- /library/lib/util/min_cost_flow_slope.hpp.html
title: lib/util/min_cost_flow_slope.hpp
---
