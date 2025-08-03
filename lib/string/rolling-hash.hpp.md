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
    \ 3 \"lib/string/rolling-hash.hpp\"\n\ntemplate <class mint> class RollingHash\
    \ {\n    using value_type = decltype(mint().val());\n    using u64 = unsigned\
    \ long long;\n    using u128 = __uint128_t;\n\n    static const value_type mod\
    \ = mint::mod();\n    const u128 base;\n\npublic:\n    RollingHash(const string\
    \ &s, u128 base, bool use_reverse = false)\n        : n(s.size()), hash(n + 1,\
    \ 0), pow(n + 1, 1), base(base), use_reverse(use_reverse) {\n        assert(base\
    \ <= mod - 1);\n        for(int i = 0; i < n; i++) {\n            hash[i + 1]\
    \ = hash[i] * base + s[i];\n            pow[i + 1] = pow[i] * base;\n        }\n\
    \        if(use_reverse) {\n            rev_hash.resize(n + 1, 0);\n         \
    \   for(int i = n - 1; i >= 0; i--) {\n                rev_hash[i] = rev_hash[i\
    \ + 1] * base + s[i];\n            }\n        }\n    }\n    // iterator\u3092\u53D7\
    \u3051\u53D6\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    template <class\
    \ Iterator>\n    RollingHash(const Iterator first, const Iterator last, u128 base,\
    \ bool use_reverse = false)\n        : n(distance(first, last)), hash(n + 1, 0),\
    \ pow(n + 1, 1), base(base), use_reverse(use_reverse) {\n        assert(base <=\
    \ mod - 1);\n        for(int i = 0; i < n; i++) {\n            hash[i + 1] = hash[i]\
    \ * base + *(first + i);\n            pow[i + 1] = pow[i] * base;\n        }\n\
    \        if(use_reverse) {\n            rev_hash.resize(n + 1, 0);\n         \
    \   for(int i = n - 1; i >= 0; i--) {\n                rev_hash[i] = rev_hash[i\
    \ + 1] * base + *(first + i);\n            }\n        }\n    }\n\n    // O(1)\n\
    \    // [l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n \
    \   value_type get(int l, int r) const {\n        mint res = hash[r] - hash[l]\
    \ * pow[r - l];\n        return res.val();\n    }\n    value_type get(int l) const\
    \ { return get(l, n); }\n    value_type get() const { return hash[n].val(); }\n\
    \n    // O(1)\n    // [l, r) \u306E\u9006\u5411\u304D\u30CF\u30C3\u30B7\u30E5\u5024\
    \u3092\u6C42\u3081\u308B\n    // [l, r) -> s_{r-1}, s_{r-2}, ..., s_l\n    value_type\
    \ get_rev(int l, int r) const {\n        mint res = rev_hash[l] - rev_hash[r]\
    \ * pow[r - l];\n        return res.val();\n    }\n    value_type get_rev(int\
    \ l) const { return get_rev(l, n); }\n    value_type get_rev() const { return\
    \ rev_hash[0].val(); }\n\n\nprivate:\n    int n;\n    bool use_reverse;\n    vector<mint>\
    \ hash;      // hash[i] := s[0, i)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n    vector<mint>\
    \ pow;       // pow[i] := base^i\n    vector<mint> rev_hash;  // rev_hash[i] :=\
    \ s[i, n)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\npublic:\n    // O(log(min(len1,\
    \ len2)))\n    // s1[from1, from1+len) \u3068 s2[from2, from2+len) \u306E\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u9577\u3092\u6C42\u3081\u308B\n    // rev1, rev2 \u306F\
    \u305D\u308C\u305E\u308Cs1, s2\u3092\u9006\u5411\u304D\u306B\u3059\u308B\u304B\
    \u3069\u3046\u304B\n    // \u4F8B\u3048\u3070 rev1 \u304C true \u306E\u3068\u304D\
    \u3001{s1[from1], s1[from-1], ...} \u304C\u51E6\u7406\u5BFE\u8C61\u3068\u306A\u308B\
    \u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\u308B\n    friend int matching_length(const\
    \ RollingHash<mint> &rh1, int from1, bool rev1, const RollingHash<mint> &rh2,\n\
    \                               int from2, bool rev2) {\n        assert(0 <= from1\
    \ && from1 < rh1.n);\n        assert(0 <= from2 && from2 < rh2.n);\n\n       \
    \ ll len1 = (!rev1 ? rh1.n - from1 : from1 + 1);\n        ll len2 = (!rev2 ? rh2.n\
    \ - from2 : from2 + 1);\n\n        ll ok = 0;\n        ll ng = min(len1, len2)\
    \ + 1;\n        while(abs(ok - ng) > 1) {\n            ll mid = (ok + ng) / 2;\n\
    \            ll hash1 = !rev1 ? rh1.get(from1, from1 + mid) : rh1.get_rev(from1\
    \ + 1 - mid, from1 + 1);\n            ll hash2 = !rev2 ? rh2.get(from2, from2\
    \ + mid) : rh2.get_rev(from2 + 1 - mid, from2 + 1);\n            if(hash1 == hash2)\
    \ ok = mid;\n            else ng = mid;\n        }\n        return ok;\n    }\n\
    \n    // O(log(min(len1, len2)))\n    // s1[from1, from1+len) \u3068 s2[from2,\
    \ from2+len) \u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u9577\u3092\u6C42\u3081\u308B\
    \n    // \u3069\u3061\u3089\u3082\u9006\u5411\u304D\u3067\u306A\u3044\u5834\u5408\
    \n    friend int matching_length(const RollingHash<mint> &rh1, int from1, const\
    \ RollingHash<mint> &rh2, int from2) {\n        return matching_length(rh1, from1,\
    \ false, rh2, from2, false);\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\ntemplate <class mint> class\
    \ RollingHash {\n    using value_type = decltype(mint().val());\n    using u64\
    \ = unsigned long long;\n    using u128 = __uint128_t;\n\n    static const value_type\
    \ mod = mint::mod();\n    const u128 base;\n\npublic:\n    RollingHash(const string\
    \ &s, u128 base, bool use_reverse = false)\n        : n(s.size()), hash(n + 1,\
    \ 0), pow(n + 1, 1), base(base), use_reverse(use_reverse) {\n        assert(base\
    \ <= mod - 1);\n        for(int i = 0; i < n; i++) {\n            hash[i + 1]\
    \ = hash[i] * base + s[i];\n            pow[i + 1] = pow[i] * base;\n        }\n\
    \        if(use_reverse) {\n            rev_hash.resize(n + 1, 0);\n         \
    \   for(int i = n - 1; i >= 0; i--) {\n                rev_hash[i] = rev_hash[i\
    \ + 1] * base + s[i];\n            }\n        }\n    }\n    // iterator\u3092\u53D7\
    \u3051\u53D6\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    template <class\
    \ Iterator>\n    RollingHash(const Iterator first, const Iterator last, u128 base,\
    \ bool use_reverse = false)\n        : n(distance(first, last)), hash(n + 1, 0),\
    \ pow(n + 1, 1), base(base), use_reverse(use_reverse) {\n        assert(base <=\
    \ mod - 1);\n        for(int i = 0; i < n; i++) {\n            hash[i + 1] = hash[i]\
    \ * base + *(first + i);\n            pow[i + 1] = pow[i] * base;\n        }\n\
    \        if(use_reverse) {\n            rev_hash.resize(n + 1, 0);\n         \
    \   for(int i = n - 1; i >= 0; i--) {\n                rev_hash[i] = rev_hash[i\
    \ + 1] * base + *(first + i);\n            }\n        }\n    }\n\n    // O(1)\n\
    \    // [l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n \
    \   value_type get(int l, int r) const {\n        mint res = hash[r] - hash[l]\
    \ * pow[r - l];\n        return res.val();\n    }\n    value_type get(int l) const\
    \ { return get(l, n); }\n    value_type get() const { return hash[n].val(); }\n\
    \n    // O(1)\n    // [l, r) \u306E\u9006\u5411\u304D\u30CF\u30C3\u30B7\u30E5\u5024\
    \u3092\u6C42\u3081\u308B\n    // [l, r) -> s_{r-1}, s_{r-2}, ..., s_l\n    value_type\
    \ get_rev(int l, int r) const {\n        mint res = rev_hash[l] - rev_hash[r]\
    \ * pow[r - l];\n        return res.val();\n    }\n    value_type get_rev(int\
    \ l) const { return get_rev(l, n); }\n    value_type get_rev() const { return\
    \ rev_hash[0].val(); }\n\n\nprivate:\n    int n;\n    bool use_reverse;\n    vector<mint>\
    \ hash;      // hash[i] := s[0, i)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n    vector<mint>\
    \ pow;       // pow[i] := base^i\n    vector<mint> rev_hash;  // rev_hash[i] :=\
    \ s[i, n)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\npublic:\n    // O(log(min(len1,\
    \ len2)))\n    // s1[from1, from1+len) \u3068 s2[from2, from2+len) \u306E\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u9577\u3092\u6C42\u3081\u308B\n    // rev1, rev2 \u306F\
    \u305D\u308C\u305E\u308Cs1, s2\u3092\u9006\u5411\u304D\u306B\u3059\u308B\u304B\
    \u3069\u3046\u304B\n    // \u4F8B\u3048\u3070 rev1 \u304C true \u306E\u3068\u304D\
    \u3001{s1[from1], s1[from-1], ...} \u304C\u51E6\u7406\u5BFE\u8C61\u3068\u306A\u308B\
    \u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\u308B\n    friend int matching_length(const\
    \ RollingHash<mint> &rh1, int from1, bool rev1, const RollingHash<mint> &rh2,\n\
    \                               int from2, bool rev2) {\n        assert(0 <= from1\
    \ && from1 < rh1.n);\n        assert(0 <= from2 && from2 < rh2.n);\n\n       \
    \ ll len1 = (!rev1 ? rh1.n - from1 : from1 + 1);\n        ll len2 = (!rev2 ? rh2.n\
    \ - from2 : from2 + 1);\n\n        ll ok = 0;\n        ll ng = min(len1, len2)\
    \ + 1;\n        while(abs(ok - ng) > 1) {\n            ll mid = (ok + ng) / 2;\n\
    \            ll hash1 = !rev1 ? rh1.get(from1, from1 + mid) : rh1.get_rev(from1\
    \ + 1 - mid, from1 + 1);\n            ll hash2 = !rev2 ? rh2.get(from2, from2\
    \ + mid) : rh2.get_rev(from2 + 1 - mid, from2 + 1);\n            if(hash1 == hash2)\
    \ ok = mid;\n            else ng = mid;\n        }\n        return ok;\n    }\n\
    \n    // O(log(min(len1, len2)))\n    // s1[from1, from1+len) \u3068 s2[from2,\
    \ from2+len) \u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u9577\u3092\u6C42\u3081\u308B\
    \n    // \u3069\u3061\u3089\u3082\u9006\u5411\u304D\u3067\u306A\u3044\u5834\u5408\
    \n    friend int matching_length(const RollingHash<mint> &rh1, int from1, const\
    \ RollingHash<mint> &rh2, int from2) {\n        return matching_length(rh1, from1,\
    \ false, rh2, from2, false);\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/rolling-hash.hpp
layout: document
redirect_from:
- /library/lib/string/rolling-hash.hpp
- /library/lib/string/rolling-hash.hpp.html
title: lib/string/rolling-hash.hpp
---
