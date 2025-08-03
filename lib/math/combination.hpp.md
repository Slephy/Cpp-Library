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
    \ 3 \"lib/math/combination.hpp\"\n\nnamespace slephy_combination {\ntemplate <class\
    \ Float> class Combination_Float {\n    vector<Float> fac_, finv_, inv_;\n   \
    \ const int MAX_SZ = 150;\n\npublic:\n    Combination_Float() { init_sz(MAX_SZ);\
    \ }\n    Combination_Float(int n) { init_sz(min(n + 1, MAX_SZ)); }\n\n    // O(k)\n\
    \    Float C(ll n, ll k) {\n        if(n < k) return 0;\n        if(n < 0 || k\
    \ < 0) return 0;\n\n        if(k > n - k) k = n - k;\n\n        Float ret = 1.0;\n\
    \        for(int i = 1; i <= k; ++i) {\n            ret *= Float(n - i + 1) /\
    \ Float(i);\n        }\n        return ret;\n    }\n\n    // O(k)\n    Float P(ll\
    \ n, ll k) {\n        if(n < k) return 0;\n        if(n < 0 || k < 0) return 0;\n\
    \        Float ret = 1.0;\n        for(int i = 0; i < k; ++i) {\n            ret\
    \ *= Float(n - i);\n        }\n        return ret;\n    }\n\n    // O(k)\n   \
    \ Float H(ll n, ll k) {\n        if(n == 0 && k == 0) return 1;\n        return\
    \ C(n + k - 1, k);\n    }\n\n    // O(k)\n    Float C_naive(ll n, ll k) { return\
    \ C(n, k); }\n\n    Float fac(ll n) { return fac_[n]; }\n    Float finv(ll n)\
    \ { return finv_[n]; }\n    Float inv(ll n) { return inv_[n]; }\n\n\nprivate:\n\
    \    void init_sz(ll sz) {\n        if(sz < 2) sz = 2;\n        fac_.resize(sz);\n\
    \        finv_.resize(sz);\n        inv_.resize(sz);\n        fac_[0] = fac_[1]\
    \ = 1.0;\n        finv_[0] = finv_[1] = 1.0;\n        inv_[1] = 1.0;\n       \
    \ for(ll i = 2; i < sz; ++i) {\n            fac_[i] = fac_[i - 1] * i;\n     \
    \       inv_[i] = 1.0 / i;\n            finv_[i] = finv_[i - 1] * inv_[i];\n \
    \       }\n    }\n};\n\ntemplate <class mint> class Combination_Modint {\n   \
    \ vector<mint> fac_, finv_, inv_;\n    int sz;\n\npublic:\n    Combination_Modint()\
    \ : fac_(), finv_(), inv_(), sz(0) {}\n    Combination_Modint(int n) : fac_(n\
    \ + 1), finv_(n + 1), inv_(n + 1), sz(0) { update_sz(n + 1); }\n\n    mint C(ll\
    \ n, ll k) {\n        update_sz(n + 1);\n        if(n < k) return 0;\n       \
    \ if(n < 0 || k < 0) return 0;\n        return fac_[n] * finv_[k] * finv_[n -\
    \ k];\n    }\n\n    mint P(ll n, ll k) {\n        update_sz(n + 1);\n        if(n\
    \ < k) return 0;\n        if(n < 0 || k < 0) return 0;\n        return fac_[n]\
    \ * finv_[n - k];\n    }\n\n    mint H(ll n, ll k) {\n        if(n == 0 && k ==\
    \ 0) return 1;\n        return C(n + k - 1, k);\n    }\n\n    // O(k)\n    mint\
    \ C_naive(ll n, ll k) {\n        update_sz(k + 1);\n        if(n < k) return 0;\n\
    \        if(n < 0 || k < 0) return 0;\n        mint ret = 1;\n        for(ll i\
    \ = 0; i < k; i++) {\n            ret *= n - i;\n            ret *= inv_[i + 1];\n\
    \        }\n        return ret;\n    }\n\n    mint fac(ll n) {\n        update_sz(n\
    \ + 1);\n        return fac_[n];\n    }\n    mint finv(ll n) {\n        update_sz(n\
    \ + 1);\n        return finv_[n];\n    }\n    mint inv(ll n) {\n        update_sz(n\
    \ + 1);\n        return inv_[n];\n    }\n\nprivate:\n    void update_sz(ll new_sz)\
    \ {\n        if(sz >= new_sz) return;\n        if(new_sz < 2) new_sz = 2;\n  \
    \      fac_.resize(new_sz);\n        finv_.resize(new_sz);\n        inv_.resize(new_sz);\n\
    \        if(sz == 0) {\n            fac_[0] = fac_[1] = 1;\n            finv_[0]\
    \ = finv_[1] = 1;\n            inv_[1] = 1;\n            sz = 2;\n        }\n\
    \        for(ll i = sz; i < new_sz; i++) {\n            fac_[i] = fac_[i - 1]\
    \ * i;\n            inv_[i] = -(inv_[mint::mod() % i] * (mint::mod() / i));\n\
    \            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n        sz = new_sz;\n\
    \    }\n};\n};  // namespace slephy_combination\n\ntemplate <class T>\nusing Combination\
    \ = conditional_t<std::floating_point<T>, slephy_combination::Combination_Float<T>,\n\
    \                                  slephy_combination::Combination_Modint<T>>;\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\nnamespace slephy_combination\
    \ {\ntemplate <class Float> class Combination_Float {\n    vector<Float> fac_,\
    \ finv_, inv_;\n    const int MAX_SZ = 150;\n\npublic:\n    Combination_Float()\
    \ { init_sz(MAX_SZ); }\n    Combination_Float(int n) { init_sz(min(n + 1, MAX_SZ));\
    \ }\n\n    // O(k)\n    Float C(ll n, ll k) {\n        if(n < k) return 0;\n \
    \       if(n < 0 || k < 0) return 0;\n\n        if(k > n - k) k = n - k;\n\n \
    \       Float ret = 1.0;\n        for(int i = 1; i <= k; ++i) {\n            ret\
    \ *= Float(n - i + 1) / Float(i);\n        }\n        return ret;\n    }\n\n \
    \   // O(k)\n    Float P(ll n, ll k) {\n        if(n < k) return 0;\n        if(n\
    \ < 0 || k < 0) return 0;\n        Float ret = 1.0;\n        for(int i = 0; i\
    \ < k; ++i) {\n            ret *= Float(n - i);\n        }\n        return ret;\n\
    \    }\n\n    // O(k)\n    Float H(ll n, ll k) {\n        if(n == 0 && k == 0)\
    \ return 1;\n        return C(n + k - 1, k);\n    }\n\n    // O(k)\n    Float\
    \ C_naive(ll n, ll k) { return C(n, k); }\n\n    Float fac(ll n) { return fac_[n];\
    \ }\n    Float finv(ll n) { return finv_[n]; }\n    Float inv(ll n) { return inv_[n];\
    \ }\n\n\nprivate:\n    void init_sz(ll sz) {\n        if(sz < 2) sz = 2;\n   \
    \     fac_.resize(sz);\n        finv_.resize(sz);\n        inv_.resize(sz);\n\
    \        fac_[0] = fac_[1] = 1.0;\n        finv_[0] = finv_[1] = 1.0;\n      \
    \  inv_[1] = 1.0;\n        for(ll i = 2; i < sz; ++i) {\n            fac_[i] =\
    \ fac_[i - 1] * i;\n            inv_[i] = 1.0 / i;\n            finv_[i] = finv_[i\
    \ - 1] * inv_[i];\n        }\n    }\n};\n\ntemplate <class mint> class Combination_Modint\
    \ {\n    vector<mint> fac_, finv_, inv_;\n    int sz;\n\npublic:\n    Combination_Modint()\
    \ : fac_(), finv_(), inv_(), sz(0) {}\n    Combination_Modint(int n) : fac_(n\
    \ + 1), finv_(n + 1), inv_(n + 1), sz(0) { update_sz(n + 1); }\n\n    mint C(ll\
    \ n, ll k) {\n        update_sz(n + 1);\n        if(n < k) return 0;\n       \
    \ if(n < 0 || k < 0) return 0;\n        return fac_[n] * finv_[k] * finv_[n -\
    \ k];\n    }\n\n    mint P(ll n, ll k) {\n        update_sz(n + 1);\n        if(n\
    \ < k) return 0;\n        if(n < 0 || k < 0) return 0;\n        return fac_[n]\
    \ * finv_[n - k];\n    }\n\n    mint H(ll n, ll k) {\n        if(n == 0 && k ==\
    \ 0) return 1;\n        return C(n + k - 1, k);\n    }\n\n    // O(k)\n    mint\
    \ C_naive(ll n, ll k) {\n        update_sz(k + 1);\n        if(n < k) return 0;\n\
    \        if(n < 0 || k < 0) return 0;\n        mint ret = 1;\n        for(ll i\
    \ = 0; i < k; i++) {\n            ret *= n - i;\n            ret *= inv_[i + 1];\n\
    \        }\n        return ret;\n    }\n\n    mint fac(ll n) {\n        update_sz(n\
    \ + 1);\n        return fac_[n];\n    }\n    mint finv(ll n) {\n        update_sz(n\
    \ + 1);\n        return finv_[n];\n    }\n    mint inv(ll n) {\n        update_sz(n\
    \ + 1);\n        return inv_[n];\n    }\n\nprivate:\n    void update_sz(ll new_sz)\
    \ {\n        if(sz >= new_sz) return;\n        if(new_sz < 2) new_sz = 2;\n  \
    \      fac_.resize(new_sz);\n        finv_.resize(new_sz);\n        inv_.resize(new_sz);\n\
    \        if(sz == 0) {\n            fac_[0] = fac_[1] = 1;\n            finv_[0]\
    \ = finv_[1] = 1;\n            inv_[1] = 1;\n            sz = 2;\n        }\n\
    \        for(ll i = sz; i < new_sz; i++) {\n            fac_[i] = fac_[i - 1]\
    \ * i;\n            inv_[i] = -(inv_[mint::mod() % i] * (mint::mod() / i));\n\
    \            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n        sz = new_sz;\n\
    \    }\n};\n};  // namespace slephy_combination\n\ntemplate <class T>\nusing Combination\
    \ = conditional_t<std::floating_point<T>, slephy_combination::Combination_Float<T>,\n\
    \                                  slephy_combination::Combination_Modint<T>>;\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/math/combination.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/combination.hpp
layout: document
redirect_from:
- /library/lib/math/combination.hpp
- /library/lib/math/combination.hpp.html
title: lib/math/combination.hpp
---
