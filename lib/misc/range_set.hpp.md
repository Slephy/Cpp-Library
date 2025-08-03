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
    links:
    - https://mugen1337.hatenablog.com/entry/2020/10/14/134022
    - https://rsk0315.hatenablog.com/entry/2020/10/11/125049
    - https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
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
    \ 3 \"lib/misc/range_set.hpp\"\n// \u53C2\u8003\n// https://mugen1337.hatenablog.com/entry/2020/10/14/134022\n\
    // https://rsk0315.hatenablog.com/entry/2020/10/11/125049\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    enum class RangeSetType {\n    NotMergeAdjacent = 0,  // [l, x]\u3068[x, r]\u3092\
    \u7D50\u5408\u3057\u306A\u3044\n    MergeAdjcent = 1,      // [l, x]\u3068[x,\
    \ r]\u3092\u7D50\u5408\u3059\u308B\n};\n\ntemplate <class T> class RangeSet {\n\
    \    const RangeSetType rs_type;\n    const int OFFSET;\n    set<pair<T, T>> st;\n\
    \npublic:\n    const pair<T, T> npos;\n    RangeSet(RangeSetType rs_type = RangeSetType::MergeAdjcent)\n\
    \        : rs_type(rs_type),\n          OFFSET(static_cast<int>(rs_type)),\n \
    \         npos(numeric_limits<T>::max(), numeric_limits<T>::max()) {\n       \
    \ st.emplace(npos);\n        st.emplace(numeric_limits<T>::min(), numeric_limits<T>::min());\n\
    \    }\n\n    // \u9589\u533A\u9593 [l, r] \u304C\u4E00\u3064\u306E\u533A\u9593\
    \u306B\u88AB\u8986\u3055\u308C\u3066\u3044\u308B\u304B\u3092\u8FD4\u3059\n   \
    \ bool covered(T l, T r) {\n        assert(l <= r);\n        auto itr = prev(st.lower_bound({l\
    \ + 1, l + 1}));\n        return (itr->first <= l && r <= itr->second);\n    }\n\
    \n    bool covered(T x) { return covered(x, x); }\n\n    // \u9589\u533A\u9593\
    \ [l, r] \u3092\u88AB\u8986\u3059\u308B\u3088\u3046\u306A\u533A\u9593\u304C\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u3070\u305D\u308C\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089\u3070 npos \u3092\u8FD4\u3059\u3002\n   \
    \ pair<T, T> covered_by(T l, T r) {\n        assert(l <= r);\n        auto itr\
    \ = prev(st.lower_bound({l + 1, l + 1}));\n        if(itr->first <= l && r <=\
    \ itr->second) return *itr;\n        else return this->npos;\n    }\n\n    pair<T,\
    \ T> covered_by(T x) { return covered_by(x, x); }\n\n    // \u9589\u533A\u9593\
    \ [l, r] \u3092\u633F\u5165\u3057\u3001\u8981\u7D20\u306E\u5897\u52A0\u91CF\u3092\
    \u8FD4\u3059\n    T insert(T l, T r) {\n        assert(l <= r);\n        auto\
    \ itr = prev(st.lower_bound({l + 1, l + 1}));\n        // \u2705 itr->first <=\
    \ l\n\n        T ret = 0;\n        auto update_ret = [&ret](auto itr) -> void\
    \ { ret -= (itr->second - itr->first + 1); };\n        if(itr->second >= r) {\
    \  // *itr\u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u3068\u304D\
    \n            return 0;\n        }\n        else if(itr->second + OFFSET >= l)\
    \ {  // *itr\u3068\u5171\u901A\u90E8\u5206\u3092\u6301\u3064\u3068\u304D\u3001\
    merge\n            update_ret(itr);\n            l = itr->first;\n           \
    \ itr = st.erase(itr);\n        }\n        else {  // \u305D\u3046\u3067\u306A\
    \u3044\u3068\u304D\u3001skip\n            itr = next(itr);\n        }\n      \
    \  // \u2705 itr->first > l\n\n        // *itr\u304C[l, r]\u306B\u5B8C\u5168\u306B\
    \u5305\u542B\u3055\u308C\u308B\u3068\u304D\n        while(itr->second <= r) {\n\
    \            update_ret(itr);\n            itr = st.erase(itr);\n        }\n \
    \       // \u2705 itr->first >= l && itr->second > r\n\n        if(itr->first\
    \ <= r + OFFSET) {\n            update_ret(itr);\n            r = itr->second;\n\
    \            st.erase(itr);\n        }\n\n        st.emplace(l, r);\n        ret\
    \ += r - l + 1;\n        return ret;\n    }\n\n    T insert(T x) { return insert(x,\
    \ x); }\n\n    // \u9589\u533A\u9593 [l, r] \u3092\u524A\u9664\u3057\u3001\u8981\
    \u7D20\u306E\u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T l, T r) {\n  \
    \      assert(l <= r);\n        auto itr = prev(st.lower_bound({l + 1, l + 1}));\n\
    \        // \u2705 itr->first <= l\n\n        // *itr\u306B\u5B8C\u5168\u306B\u542B\
    \u307E\u308C\u3066\u3044\u308B\n        if(r <= itr->second) {\n            if(itr->first\
    \ < l) st.emplace(itr->first, l - 1);\n            if(r < itr->second) st.emplace(r\
    \ + 1, itr->second);\n            st.erase(itr);\n            return r - l + 1;\n\
    \        }\n\n        T ret = 0;\n        if(l <= itr->second) {\n           \
    \ ret += itr->second - l + 1;\n            if(itr->first < l) st.emplace(itr->first,\
    \ l - 1);\n            itr = st.erase(itr);\n        }\n        else {\n     \
    \       itr = next(itr);\n        }\n        // \u2705 itr->first > l\n\n    \
    \    while(itr->second <= r) {\n            ret += itr->second - itr->first +\
    \ 1;\n            itr = st.erase(itr);\n        }\n\n        if(itr->first <=\
    \ r) {\n            ret += r - itr->first + 1;\n            if(r < itr->second)\
    \ st.emplace(r + 1, itr->second);\n            st.erase(itr);\n        }\n   \
    \     return ret;\n    }\n\n    T erase(T x) { return erase(x, x); }\n\n    //\
    \ \u683C\u7D0D\u3055\u308C\u3066\u3044\u308B\u9589\u533A\u9593\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n    int size() { return (int)st.size() - 2; }\n\n    // x\
    \ \u4EE5\u4E0A\u306E\u5024\u3067\u3001\u3069\u306E\u533A\u9593\u306B\u3082\u542B\
    \u307E\u308C\u306A\u3044\u6574\u6570\u306E\u3046\u3061\u6700\u5C0F\u306E\u6574\
    \u6570\u3092\u8FD4\u3059\n    T mex(T x = 0) {\n        auto itr = prev(st.lower_bound({x\
    \ + 1, x + 1}));\n        if(x <= itr->second) return itr->second + 1;\n     \
    \   else return x;\n    }\n\n    // x, y \u304C\u540C\u3058\u9589\u533A\u9593\u306B\
    \u542B\u307E\u308C\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\n    // x, y \u306E\
    \u3044\u305A\u308C\u304B\u304C\u3069\u306E\u9589\u533A\u9593\u306B\u3082\u542B\
    \u307E\u308C\u306A\u3044\u306E\u3067\u3042\u308C\u3070 false \u3068\u5224\u5B9A\
    \u3059\u308B\n    bool same(T x, T y) {\n        auto cover_x = covered_by(x);\n\
    \        auto cover_y = covered_by(y);\n        if(cover_x == this->npos || cover_y\
    \ == this->npos) return false;\n        else return (cover_x == cover_y);\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u53C2\u8003\n// https://mugen1337.hatenablog.com/entry/2020/10/14/134022\n\
    // https://rsk0315.hatenablog.com/entry/2020/10/11/125049\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    enum class RangeSetType {\n    NotMergeAdjacent = 0,  // [l, x]\u3068[x, r]\u3092\
    \u7D50\u5408\u3057\u306A\u3044\n    MergeAdjcent = 1,      // [l, x]\u3068[x,\
    \ r]\u3092\u7D50\u5408\u3059\u308B\n};\n\ntemplate <class T> class RangeSet {\n\
    \    const RangeSetType rs_type;\n    const int OFFSET;\n    set<pair<T, T>> st;\n\
    \npublic:\n    const pair<T, T> npos;\n    RangeSet(RangeSetType rs_type = RangeSetType::MergeAdjcent)\n\
    \        : rs_type(rs_type),\n          OFFSET(static_cast<int>(rs_type)),\n \
    \         npos(numeric_limits<T>::max(), numeric_limits<T>::max()) {\n       \
    \ st.emplace(npos);\n        st.emplace(numeric_limits<T>::min(), numeric_limits<T>::min());\n\
    \    }\n\n    // \u9589\u533A\u9593 [l, r] \u304C\u4E00\u3064\u306E\u533A\u9593\
    \u306B\u88AB\u8986\u3055\u308C\u3066\u3044\u308B\u304B\u3092\u8FD4\u3059\n   \
    \ bool covered(T l, T r) {\n        assert(l <= r);\n        auto itr = prev(st.lower_bound({l\
    \ + 1, l + 1}));\n        return (itr->first <= l && r <= itr->second);\n    }\n\
    \n    bool covered(T x) { return covered(x, x); }\n\n    // \u9589\u533A\u9593\
    \ [l, r] \u3092\u88AB\u8986\u3059\u308B\u3088\u3046\u306A\u533A\u9593\u304C\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u3070\u305D\u308C\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089\u3070 npos \u3092\u8FD4\u3059\u3002\n   \
    \ pair<T, T> covered_by(T l, T r) {\n        assert(l <= r);\n        auto itr\
    \ = prev(st.lower_bound({l + 1, l + 1}));\n        if(itr->first <= l && r <=\
    \ itr->second) return *itr;\n        else return this->npos;\n    }\n\n    pair<T,\
    \ T> covered_by(T x) { return covered_by(x, x); }\n\n    // \u9589\u533A\u9593\
    \ [l, r] \u3092\u633F\u5165\u3057\u3001\u8981\u7D20\u306E\u5897\u52A0\u91CF\u3092\
    \u8FD4\u3059\n    T insert(T l, T r) {\n        assert(l <= r);\n        auto\
    \ itr = prev(st.lower_bound({l + 1, l + 1}));\n        // \u2705 itr->first <=\
    \ l\n\n        T ret = 0;\n        auto update_ret = [&ret](auto itr) -> void\
    \ { ret -= (itr->second - itr->first + 1); };\n        if(itr->second >= r) {\
    \  // *itr\u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u3068\u304D\
    \n            return 0;\n        }\n        else if(itr->second + OFFSET >= l)\
    \ {  // *itr\u3068\u5171\u901A\u90E8\u5206\u3092\u6301\u3064\u3068\u304D\u3001\
    merge\n            update_ret(itr);\n            l = itr->first;\n           \
    \ itr = st.erase(itr);\n        }\n        else {  // \u305D\u3046\u3067\u306A\
    \u3044\u3068\u304D\u3001skip\n            itr = next(itr);\n        }\n      \
    \  // \u2705 itr->first > l\n\n        // *itr\u304C[l, r]\u306B\u5B8C\u5168\u306B\
    \u5305\u542B\u3055\u308C\u308B\u3068\u304D\n        while(itr->second <= r) {\n\
    \            update_ret(itr);\n            itr = st.erase(itr);\n        }\n \
    \       // \u2705 itr->first >= l && itr->second > r\n\n        if(itr->first\
    \ <= r + OFFSET) {\n            update_ret(itr);\n            r = itr->second;\n\
    \            st.erase(itr);\n        }\n\n        st.emplace(l, r);\n        ret\
    \ += r - l + 1;\n        return ret;\n    }\n\n    T insert(T x) { return insert(x,\
    \ x); }\n\n    // \u9589\u533A\u9593 [l, r] \u3092\u524A\u9664\u3057\u3001\u8981\
    \u7D20\u306E\u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T l, T r) {\n  \
    \      assert(l <= r);\n        auto itr = prev(st.lower_bound({l + 1, l + 1}));\n\
    \        // \u2705 itr->first <= l\n\n        // *itr\u306B\u5B8C\u5168\u306B\u542B\
    \u307E\u308C\u3066\u3044\u308B\n        if(r <= itr->second) {\n            if(itr->first\
    \ < l) st.emplace(itr->first, l - 1);\n            if(r < itr->second) st.emplace(r\
    \ + 1, itr->second);\n            st.erase(itr);\n            return r - l + 1;\n\
    \        }\n\n        T ret = 0;\n        if(l <= itr->second) {\n           \
    \ ret += itr->second - l + 1;\n            if(itr->first < l) st.emplace(itr->first,\
    \ l - 1);\n            itr = st.erase(itr);\n        }\n        else {\n     \
    \       itr = next(itr);\n        }\n        // \u2705 itr->first > l\n\n    \
    \    while(itr->second <= r) {\n            ret += itr->second - itr->first +\
    \ 1;\n            itr = st.erase(itr);\n        }\n\n        if(itr->first <=\
    \ r) {\n            ret += r - itr->first + 1;\n            if(r < itr->second)\
    \ st.emplace(r + 1, itr->second);\n            st.erase(itr);\n        }\n   \
    \     return ret;\n    }\n\n    T erase(T x) { return erase(x, x); }\n\n    //\
    \ \u683C\u7D0D\u3055\u308C\u3066\u3044\u308B\u9589\u533A\u9593\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n    int size() { return (int)st.size() - 2; }\n\n    // x\
    \ \u4EE5\u4E0A\u306E\u5024\u3067\u3001\u3069\u306E\u533A\u9593\u306B\u3082\u542B\
    \u307E\u308C\u306A\u3044\u6574\u6570\u306E\u3046\u3061\u6700\u5C0F\u306E\u6574\
    \u6570\u3092\u8FD4\u3059\n    T mex(T x = 0) {\n        auto itr = prev(st.lower_bound({x\
    \ + 1, x + 1}));\n        if(x <= itr->second) return itr->second + 1;\n     \
    \   else return x;\n    }\n\n    // x, y \u304C\u540C\u3058\u9589\u533A\u9593\u306B\
    \u542B\u307E\u308C\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\n    // x, y \u306E\
    \u3044\u305A\u308C\u304B\u304C\u3069\u306E\u9589\u533A\u9593\u306B\u3082\u542B\
    \u307E\u308C\u306A\u3044\u306E\u3067\u3042\u308C\u3070 false \u3068\u5224\u5B9A\
    \u3059\u308B\n    bool same(T x, T y) {\n        auto cover_x = covered_by(x);\n\
    \        auto cover_y = covered_by(y);\n        if(cover_x == this->npos || cover_y\
    \ == this->npos) return false;\n        else return (cover_x == cover_y);\n  \
    \  }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/misc/range_set.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/range_set.hpp
layout: document
redirect_from:
- /library/lib/misc/range_set.hpp
- /library/lib/misc/range_set.hpp.html
title: lib/misc/range_set.hpp
---
