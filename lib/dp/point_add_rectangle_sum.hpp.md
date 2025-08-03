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
    \ 3 \"lib/dp/point_add_rectangle_sum.hpp\"\n// N\u56DE\u306E\u9802\u70B9\u8FFD\
    \u52A0\u30AF\u30A8\u30EA\u3068Q\u56DE\u306E\u77E9\u5F62\u30AF\u30A8\u30EA\u3092\
    \u3054\u3061\u3083\u307E\u305C\u306B\u51E6\u7406\u3059\u308B\n// PosType: \u5EA7\
    \u6A19\u306E\u578B(int, double\u7B49)\n// WeightType: \u91CD\u307F\u306E\u578B\
    \n// @need StaticRectangleSum\ntemplate <totally_ordered PosType, class WeightType>\
    \ class PointAddRectangleSum {\n    using Point_t = tuple<PosType, PosType, WeightType>;\n\
    \    using Query_t = tuple<PosType, PosType, PosType, PosType>;\n\npublic:\n \
    \   PointAddRectangleSum() {}\n    PointAddRectangleSum(const vector<variant<Point_t,\
    \ Query_t>> &queries) : queries(queries) {}\n\n    // \u70B9(x, y) \u306B\u91CD\
    \u307F w \u3092\u8FFD\u52A0\n    void add_point(PosType x, PosType y, WeightType\
    \ w) { queries.emplace_back(x, y, w); }\n\n    // [l, r) \xD7 [d, u) \u306E\u7BC4\
    \u56F2\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u30AF\u30A8\u30EA\u3092\u8FFD\
    \u52A0\n    void add_query(PosType l, PosType d, PosType r, PosType u) { queries.emplace_back(l,\
    \ d, r, u); }\n\n    // O(N logN logQ)\n    vector<WeightType> solve() {\n   \
    \     auto is_sum_query = [&](const auto &tp) -> bool { return holds_alternative<tuple<ll,\
    \ ll, ll, ll>>(tp); };\n\n        vector<int> rev(queries.size());  // rev[i]\
    \ = i\u756A\u76EE\u306E\u30AF\u30A8\u30EA\u304C\u4F55\u756A\u76EE\u306Esum_query\u304B\
    \n        vector<ll> ans;\n        {\n            int iter = 0;\n            for(int\
    \ i = 0; i < queries.size(); i++) {\n                if(is_sum_query(queries[i]))\
    \ {\n                    rev[i] = iter++;\n                }\n            }\n\
    \            ans.resize(iter);\n        }\n\n        // \u5206\u5272\u7D71\u6CBB\
    \n        queue<pair<ll, ll>> que;\n        que.emplace(0, queries.size());\n\
    \        while(!que.empty()) {\n            auto [l, r] = que.front();\n     \
    \       que.pop();\n            if(r - l <= 1) continue;\n            ll m = (l\
    \ + r) / 2;\n            que.emplace(l, m);\n            que.emplace(m, r);\n\n\
    \            // [l, m) \u306E\u9802\u70B9\u8FFD\u52A0\u304B\u3089 [m, r) \u306E\
    \u77E9\u5F62\u30AF\u30A8\u30EA\u3078\u306E\u5BC4\u4E0E\u3092\u8A08\u7B97\n   \
    \         vector<tuple<ll, ll, ll>> points;\n            vector<tuple<ll, ll,\
    \ ll, ll>> sum_queries;\n            for(int i = l; i < m; i++) {\n          \
    \      if(!is_sum_query(queries[i])) {\n                    points.push_back(get<tuple<ll,\
    \ ll, ll>>(queries[i]));\n                }\n            }\n            for(int\
    \ i = m; i < r; i++) {\n                if(is_sum_query(queries[i])) {\n     \
    \               sum_queries.push_back(get<tuple<ll, ll, ll, ll>>(queries[i]));\n\
    \                }\n            }\n\n            StaticRectangleSum<ll, ll> srs(points,\
    \ sum_queries);\n            auto res = srs.solve();\n            for(int i =\
    \ m, iter = 0; i < r; i++) {\n                if(is_sum_query(queries[i])) {\n\
    \                    ans[rev[i]] += res[iter];\n                    iter++;\n\
    \                }\n            }\n        }\n        return ans;\n    }\n\nprivate:\n\
    \    vector<variant<Point_t, Query_t>> queries;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// N\u56DE\u306E\u9802\u70B9\
    \u8FFD\u52A0\u30AF\u30A8\u30EA\u3068Q\u56DE\u306E\u77E9\u5F62\u30AF\u30A8\u30EA\
    \u3092\u3054\u3061\u3083\u307E\u305C\u306B\u51E6\u7406\u3059\u308B\n// PosType:\
    \ \u5EA7\u6A19\u306E\u578B(int, double\u7B49)\n// WeightType: \u91CD\u307F\u306E\
    \u578B\n// @need StaticRectangleSum\ntemplate <totally_ordered PosType, class\
    \ WeightType> class PointAddRectangleSum {\n    using Point_t = tuple<PosType,\
    \ PosType, WeightType>;\n    using Query_t = tuple<PosType, PosType, PosType,\
    \ PosType>;\n\npublic:\n    PointAddRectangleSum() {}\n    PointAddRectangleSum(const\
    \ vector<variant<Point_t, Query_t>> &queries) : queries(queries) {}\n\n    //\
    \ \u70B9(x, y) \u306B\u91CD\u307F w \u3092\u8FFD\u52A0\n    void add_point(PosType\
    \ x, PosType y, WeightType w) { queries.emplace_back(x, y, w); }\n\n    // [l,\
    \ r) \xD7 [d, u) \u306E\u7BC4\u56F2\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u30AF\
    \u30A8\u30EA\u3092\u8FFD\u52A0\n    void add_query(PosType l, PosType d, PosType\
    \ r, PosType u) { queries.emplace_back(l, d, r, u); }\n\n    // O(N logN logQ)\n\
    \    vector<WeightType> solve() {\n        auto is_sum_query = [&](const auto\
    \ &tp) -> bool { return holds_alternative<tuple<ll, ll, ll, ll>>(tp); };\n\n \
    \       vector<int> rev(queries.size());  // rev[i] = i\u756A\u76EE\u306E\u30AF\
    \u30A8\u30EA\u304C\u4F55\u756A\u76EE\u306Esum_query\u304B\n        vector<ll>\
    \ ans;\n        {\n            int iter = 0;\n            for(int i = 0; i < queries.size();\
    \ i++) {\n                if(is_sum_query(queries[i])) {\n                   \
    \ rev[i] = iter++;\n                }\n            }\n            ans.resize(iter);\n\
    \        }\n\n        // \u5206\u5272\u7D71\u6CBB\n        queue<pair<ll, ll>>\
    \ que;\n        que.emplace(0, queries.size());\n        while(!que.empty()) {\n\
    \            auto [l, r] = que.front();\n            que.pop();\n            if(r\
    \ - l <= 1) continue;\n            ll m = (l + r) / 2;\n            que.emplace(l,\
    \ m);\n            que.emplace(m, r);\n\n            // [l, m) \u306E\u9802\u70B9\
    \u8FFD\u52A0\u304B\u3089 [m, r) \u306E\u77E9\u5F62\u30AF\u30A8\u30EA\u3078\u306E\
    \u5BC4\u4E0E\u3092\u8A08\u7B97\n            vector<tuple<ll, ll, ll>> points;\n\
    \            vector<tuple<ll, ll, ll, ll>> sum_queries;\n            for(int i\
    \ = l; i < m; i++) {\n                if(!is_sum_query(queries[i])) {\n      \
    \              points.push_back(get<tuple<ll, ll, ll>>(queries[i]));\n       \
    \         }\n            }\n            for(int i = m; i < r; i++) {\n       \
    \         if(is_sum_query(queries[i])) {\n                    sum_queries.push_back(get<tuple<ll,\
    \ ll, ll, ll>>(queries[i]));\n                }\n            }\n\n           \
    \ StaticRectangleSum<ll, ll> srs(points, sum_queries);\n            auto res =\
    \ srs.solve();\n            for(int i = m, iter = 0; i < r; i++) {\n         \
    \       if(is_sum_query(queries[i])) {\n                    ans[rev[i]] += res[iter];\n\
    \                    iter++;\n                }\n            }\n        }\n  \
    \      return ans;\n    }\n\nprivate:\n    vector<variant<Point_t, Query_t>> queries;\n\
    };\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/point_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/lib/dp/point_add_rectangle_sum.hpp
- /library/lib/dp/point_add_rectangle_sum.hpp.html
title: lib/dp/point_add_rectangle_sum.hpp
---
