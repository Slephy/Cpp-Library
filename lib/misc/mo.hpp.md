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
    \ 3 \"lib/misc/mo.hpp\"\n// Mo's algorithm\n// [l, r) \u306E\u534A\u958B\u533A\
    \u9593\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\
    \n// solve\u306F\u4F55\u5EA6\u3067\u3082\u547C\u3073\u51FA\u3057\u53EF\u80FD\n\
    template <class AnsType> class Mo {\n    ll n, q;\n    vector<int> l, r;\n   \
    \ vector<int> order;\n    int blockSize;\n\npublic:\n    Mo(ll n, const vector<int>\
    \ &l, const vector<int> &r)\n        : n(n),\n          q(l.size()),\n       \
    \   l(l),\n          r(r),\n          order(q),\n          blockSize(max<int>(1,\
    \ 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)))) {\n        assert(l.size()\
    \ == r.size());\n        sort_query();\n    }\n\n    template <class AddLeft,\
    \ class AddRight, class DelLeft, class DelRight, class GetAns>\n    vector<AnsType>\
    \ solve(AddLeft &add_left, AddRight &add_right, DelLeft &del_left, DelRight &del_right,\n\
    \                          GetAns &get_ans) {\n        vector<AnsType> ans(q);\n\
    \        int curL = 0, curR = 0;\n        for(int i = 0; i < q; i++) {\n     \
    \       int id = order[i];\n            while(curL > l[id]) add_left(--curL);\n\
    \            while(curR < r[id]) add_right(curR++);\n            while(curL <\
    \ l[id]) del_left(curL++);\n            while(curR > r[id]) del_right(--curR);\n\
    \            ans[id] = get_ans(order[i]);\n        }\n        return ans;\n  \
    \  }\n\n    // void add(int i) : add i-th element\n    // void del(int i) : delete\
    \ i-th element\n    // AnsType get_ans(int j) : return answer of j-th query\n\
    \    template <class Add, class Del, class GetAns> vector<AnsType> solve(Add &add,\
    \ Del &del, GetAns &get_ans) {\n        return solve(add, add, del, del, get_ans);\n\
    \    }\n\nprivate:\n    void sort_query() {\n        iota(order.begin(), order.end(),\
    \ 0);\n        vector<int> block_id(q);\n        for(int i = 0; i < q; i++) block_id[i]\
    \ = l[i] / blockSize;\n        sort(order.begin(), order.end(), [&](int i, int\
    \ j) {\n            if(block_id[i] != block_id[j]) return l[i] < l[j];\n     \
    \       if(block_id[i] % 2 == 0) return r[i] < r[j];\n            return r[i]\
    \ > r[j];\n        });\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// Mo's algorithm\n// [l, r)\
    \ \u306E\u534A\u958B\u533A\u9593\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\n// solve\u306F\u4F55\u5EA6\u3067\u3082\u547C\u3073\u51FA\
    \u3057\u53EF\u80FD\ntemplate <class AnsType> class Mo {\n    ll n, q;\n    vector<int>\
    \ l, r;\n    vector<int> order;\n    int blockSize;\n\npublic:\n    Mo(ll n, const\
    \ vector<int> &l, const vector<int> &r)\n        : n(n),\n          q(l.size()),\n\
    \          l(l),\n          r(r),\n          order(q),\n          blockSize(max<int>(1,\
    \ 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)))) {\n        assert(l.size()\
    \ == r.size());\n        sort_query();\n    }\n\n    template <class AddLeft,\
    \ class AddRight, class DelLeft, class DelRight, class GetAns>\n    vector<AnsType>\
    \ solve(AddLeft &add_left, AddRight &add_right, DelLeft &del_left, DelRight &del_right,\n\
    \                          GetAns &get_ans) {\n        vector<AnsType> ans(q);\n\
    \        int curL = 0, curR = 0;\n        for(int i = 0; i < q; i++) {\n     \
    \       int id = order[i];\n            while(curL > l[id]) add_left(--curL);\n\
    \            while(curR < r[id]) add_right(curR++);\n            while(curL <\
    \ l[id]) del_left(curL++);\n            while(curR > r[id]) del_right(--curR);\n\
    \            ans[id] = get_ans(order[i]);\n        }\n        return ans;\n  \
    \  }\n\n    // void add(int i) : add i-th element\n    // void del(int i) : delete\
    \ i-th element\n    // AnsType get_ans(int j) : return answer of j-th query\n\
    \    template <class Add, class Del, class GetAns> vector<AnsType> solve(Add &add,\
    \ Del &del, GetAns &get_ans) {\n        return solve(add, add, del, del, get_ans);\n\
    \    }\n\nprivate:\n    void sort_query() {\n        iota(order.begin(), order.end(),\
    \ 0);\n        vector<int> block_id(q);\n        for(int i = 0; i < q; i++) block_id[i]\
    \ = l[i] / blockSize;\n        sort(order.begin(), order.end(), [&](int i, int\
    \ j) {\n            if(block_id[i] != block_id[j]) return l[i] < l[j];\n     \
    \       if(block_id[i] % 2 == 0) return r[i] < r[j];\n            return r[i]\
    \ > r[j];\n        });\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/misc/mo.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/mo.hpp
layout: document
redirect_from:
- /library/lib/misc/mo.hpp
- /library/lib/misc/mo.hpp.html
title: lib/misc/mo.hpp
---
