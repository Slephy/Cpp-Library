---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  - icon: ':warning:'
    path: lib/random/random.hpp
    title: lib/random/random.hpp
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
    \ 3 \"lib/random/random.hpp\"\nnamespace my_random {\nrandom_device random_dvc;\n\
    mt19937 mt(random_dvc());\n\n// l\u4EE5\u4E0Ar\u4EE5\u4E0B\u306E\u6574\u6570\u4E71\
    \u6570\u3092\u8FD4\u3059\nint rand_int(int l, int r) {\n    uniform_int_distribution<int>\
    \ dist(l, r);\n    return dist(mt);\n}\n// l\u4EE5\u4E0Ar\u4EE5\u4E0B\u306E\u6574\
    \u6570\u4E71\u6570\u3092\u8FD4\u3059\nll rand_ll(ll l, ll r) {\n    uniform_int_distribution<ll>\
    \ dist(l, r);\n    return dist(mt);\n}\n__int128_t rand_i128(__int128_t l, __int128_t\
    \ r) {\n    uniform_int_distribution<long long> dist(0, numeric_limits<long long>::max());\n\
    \    __int128_t res = dist(mt);\n    res <<= 64;\n    res += dist(mt);\n    return\
    \ res % (r - l + 1) + l;\n}\n__uint128_t rand_u128(__uint128_t l, __uint128_t\
    \ r) {\n    uniform_int_distribution<unsigned long long> dist(0, numeric_limits<unsigned\
    \ long long>::max());\n    __uint128_t res = dist(mt);\n    res <<= 64;\n    res\
    \ += dist(mt);\n    return res % (r - l + 1) + l;\n}\ndouble rand_double(double\
    \ l, double r) {\n    uniform_real_distribution<double> dist(l, r);\n    return\
    \ dist(mt);\n}\ndouble rand_double01() { return rand_double(0, 1); }\nbool rand_bool(double\
    \ probability) { return rand_double01() < probability; }\n}  // namespace my_random\n\
    using namespace my_random;\n#line 4 \"lib/misc/choosable_set.hpp\"\n// \u96C6\u5408\
    \u3092\u6271\u3046\u30AF\u30E9\u30B9\n// \u96C6\u5408\u5185\u304B\u3089\u30E9\u30F3\
    \u30C0\u30E0\u306B\u8981\u7D20\u3092\u62BD\u51FA\u3059\u308B\u64CD\u4F5C\u3092\
    \ O(1) \u3067\u3067\u304D\u308B\u306E\u304C\u5F37\u307F\uFF08set\u3060\u3068\u6642\
    \u9593\u304C\u304B\u304B\u308B\uFF09\ntemplate <class T> class ChoosableSet {\n\
    private:\n    vector<T> vec;\n    map<T, size_t> idx;  // idx[val] := (vec\u5185\
    \u3067\u306Eval\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n\n\npublic:\n    //\
    \ vector<int> \u3067\u521D\u671F\u5316. \u91CD\u8907\u8981\u7D20\u306F\u4E00\u3064\
    \u3060\u3051\u683C\u7D0D\u3055\u308C\u308B.\n    ChoosableSet(const vector<T>\
    \ &vec) {\n        for(int i = 0; i < vec.size(); i++) {\n            if(!this->contains(vec[i]))\
    \ {\n                idx[vec[i]] = this->vec.size();\n                this->vec.emplace_back(vec[i]);\n\
    \            }\n        }\n    }\n\n    // O(1)\n    int size() const { return\
    \ vec.size(); }\n\n    // O(logN)\n    bool contains(const T val) const { return\
    \ idx.count(val); }\n\n    // O(1)\n    bool empty() const { return vec.size()\
    \ == 0; }\n\n    // O(logN)\n    void emplace(const T val) {\n        if(this->contains(val))\
    \ return;\n        idx[val] = vec.size();\n        vec.emplace_back(val);\n  \
    \  }\n\n    // O(logN)\n    void erase(const int val) {\n        if(!this->contains(val))\
    \ return;\n\n        // val\u3092vec\u306E\u672B\u5C3E\u306B\u79FB\u52D5\n   \
    \     int val_index = idx.at(val);\n        if(val_index + 1 != idx.size()) {\n\
    \            idx[vec.back()] = val_index;\n            swap(vec[val_index], vec.back());\n\
    \        }\n\n        // val\u3092\u524A\u9664\n        idx.erase(val);\n    \
    \    vec.pop_back();\n    }\n\n    // O(1)\n    // \u8981\u7D20\u304B\u3089\u7121\
    \u4F5C\u70BA\u306B\u4E00\u3064\u62BD\u51FA\n    T choice() {\n        assert(!this->empty());\n\
    \        T ret = vec[rand_int(0, this->size())];\n        return ret;\n    }\n\
    \n    // O(N), \u26A0\uFE0FO(choice_num)\u3067\u306F\u306A\u3044\n    // \u6307\
    \u5B9A\u3055\u308C\u305F\u500B\u6570\u3060\u3051\u3001\u8981\u7D20\u304B\u3089\
    \u7121\u4F5C\u70BA\u306B\u62BD\u51FA\n    vector<T> choice(size_t choice_num)\
    \ {\n        assert(this->size() >= choice_num);\n        vector<T> ret;\n   \
    \     sample(vec.begin(), vec.end(), back_inserter(ret), choice_num, mt);\n  \
    \      return ret;\n    }\n\n    friend ostream &operator<<(ostream &o, const\
    \ ChoosableSet &cs) {\n        o << cs.vec;\n        return o;\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n#include \"../random/random.hpp\"\
    \n// \u96C6\u5408\u3092\u6271\u3046\u30AF\u30E9\u30B9\n// \u96C6\u5408\u5185\u304B\
    \u3089\u30E9\u30F3\u30C0\u30E0\u306B\u8981\u7D20\u3092\u62BD\u51FA\u3059\u308B\
    \u64CD\u4F5C\u3092 O(1) \u3067\u3067\u304D\u308B\u306E\u304C\u5F37\u307F\uFF08\
    set\u3060\u3068\u6642\u9593\u304C\u304B\u304B\u308B\uFF09\ntemplate <class T>\
    \ class ChoosableSet {\nprivate:\n    vector<T> vec;\n    map<T, size_t> idx;\
    \  // idx[val] := (vec\u5185\u3067\u306Eval\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9)\n\n\npublic:\n    // vector<int> \u3067\u521D\u671F\u5316. \u91CD\u8907\
    \u8981\u7D20\u306F\u4E00\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B.\n  \
    \  ChoosableSet(const vector<T> &vec) {\n        for(int i = 0; i < vec.size();\
    \ i++) {\n            if(!this->contains(vec[i])) {\n                idx[vec[i]]\
    \ = this->vec.size();\n                this->vec.emplace_back(vec[i]);\n     \
    \       }\n        }\n    }\n\n    // O(1)\n    int size() const { return vec.size();\
    \ }\n\n    // O(logN)\n    bool contains(const T val) const { return idx.count(val);\
    \ }\n\n    // O(1)\n    bool empty() const { return vec.size() == 0; }\n\n   \
    \ // O(logN)\n    void emplace(const T val) {\n        if(this->contains(val))\
    \ return;\n        idx[val] = vec.size();\n        vec.emplace_back(val);\n  \
    \  }\n\n    // O(logN)\n    void erase(const int val) {\n        if(!this->contains(val))\
    \ return;\n\n        // val\u3092vec\u306E\u672B\u5C3E\u306B\u79FB\u52D5\n   \
    \     int val_index = idx.at(val);\n        if(val_index + 1 != idx.size()) {\n\
    \            idx[vec.back()] = val_index;\n            swap(vec[val_index], vec.back());\n\
    \        }\n\n        // val\u3092\u524A\u9664\n        idx.erase(val);\n    \
    \    vec.pop_back();\n    }\n\n    // O(1)\n    // \u8981\u7D20\u304B\u3089\u7121\
    \u4F5C\u70BA\u306B\u4E00\u3064\u62BD\u51FA\n    T choice() {\n        assert(!this->empty());\n\
    \        T ret = vec[rand_int(0, this->size())];\n        return ret;\n    }\n\
    \n    // O(N), \u26A0\uFE0FO(choice_num)\u3067\u306F\u306A\u3044\n    // \u6307\
    \u5B9A\u3055\u308C\u305F\u500B\u6570\u3060\u3051\u3001\u8981\u7D20\u304B\u3089\
    \u7121\u4F5C\u70BA\u306B\u62BD\u51FA\n    vector<T> choice(size_t choice_num)\
    \ {\n        assert(this->size() >= choice_num);\n        vector<T> ret;\n   \
    \     sample(vec.begin(), vec.end(), back_inserter(ret), choice_num, mt);\n  \
    \      return ret;\n    }\n\n    friend ostream &operator<<(ostream &o, const\
    \ ChoosableSet &cs) {\n        o << cs.vec;\n        return o;\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  - lib/random/random.hpp
  isVerificationFile: false
  path: lib/misc/choosable_set.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/choosable_set.hpp
layout: document
redirect_from:
- /library/lib/misc/choosable_set.hpp
- /library/lib/misc/choosable_set.hpp.html
title: lib/misc/choosable_set.hpp
---
