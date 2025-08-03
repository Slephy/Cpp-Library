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
    \ 3 \"lib/segtree/dual_segtree.hpp\"\n\n// ACL\u306E\u9045\u5EF6\u30BB\u30B0\u6728\
    \u306E\u5B9F\u88C5\u3092\u6539\u5909\u3057\u3066\u53CC\u5BFE\u30BB\u30B0\u6728\
    \u306B\u3057\u305F\u3082\u306E\n// \u975E\u53EF\u63DB\u306A\u4F5C\u7528\u306B\u5BFE\
    \u5FDC\n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2 \u3092\u57CB\u3081\
    \u8FBC\u307F\n// add \u95A2\u6570\u3092\u8FFD\u52A0\n// size \u95A2\u6570\u3092\
    \u8FFD\u52A0\n\ntemplate <class S, class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F), F (*id)()> struct dual_segtree {\npublic:\n    dual_segtree() : dual_segtree(0)\
    \ {}\n    explicit dual_segtree(int n) : dual_segtree(vector<S>(n, S{})) {}\n\
    \    explicit dual_segtree(const vector<S>& v) : _n(int(v.size())) {\n       \
    \ log = 0;\n        while((1U << log) < (unsigned int)(_n)) log++;\n        _size\
    \ = 1 << log;\n        d = vector<S>(2 * _size);\n        lz = vector<F>(_size,\
    \ id());\n        for(int i = 0; i < _n; i++) d[_size + i] = v[i];\n    }\n\n\
    \    size_t size() const { return _n; }\n\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(p >> i);\n        d[p] = x;\n    }\n\n    void add(int p, S\
    \ x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] += x;\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    void\
    \ apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p += _size;\n\
    \        for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f,\
    \ d[p]);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if(l == r) return;\n\n        l += _size;\n   \
    \     r += _size;\n\n        for(int i = log; i >= 1; i--) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n     \
    \       while(l < r) {\n                if(l & 1) all_apply(l++, f);\n       \
    \         if(r & 1) all_apply(--r, f);\n                l >>= 1;\n           \
    \     r >>= 1;\n            }\n            l = l2;\n            r = r2;\n    \
    \    }\n    }\n\nprivate:\n    int _n, _size, log;\n    vector<S> d;\n    vector<F>\
    \ lz;\n\n    void all_apply(int k, F f) {\n        if(k >= _size) d[k] = mapping(f,\
    \ d[k]);\n        if(k < _size) lz[k] = composition(f, lz[k]);\n    }\n    void\
    \ push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1,\
    \ lz[k]);\n        lz[k] = id();\n    }\n};\n\n\ntemplate <class S, class F> struct\
    \ RangeSet_PointGet {\n    static S mapping(F f, S x) { return (f == id() ? x\
    \ : f); }\n    static F composition(F f, F g) { return (f == id() ? g : f); }\n\
    \    static F id() { return numeric_limits<F>::max(); }\n    using Type = struct\
    \ dual_segtree<S, F, mapping, composition, id>;\n};\ntemplate <class S, class\
    \ F> struct RangeAdd_PointGet {\n    static S mapping(F f, S x) { return f + x;\
    \ }\n    static F composition(F f, F g) { return f + g; }\n    static F id() {\
    \ return 0; }\n    using Type = struct dual_segtree<S, F, mapping, composition,\
    \ id>;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// ACL\u306E\u9045\u5EF6\u30BB\
    \u30B0\u6728\u306E\u5B9F\u88C5\u3092\u6539\u5909\u3057\u3066\u53CC\u5BFE\u30BB\
    \u30B0\u6728\u306B\u3057\u305F\u3082\u306E\n// \u975E\u53EF\u63DB\u306A\u4F5C\u7528\
    \u306B\u5BFE\u5FDC\n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2 \u3092\
    \u57CB\u3081\u8FBC\u307F\n// add \u95A2\u6570\u3092\u8FFD\u52A0\n// size \u95A2\
    \u6570\u3092\u8FFD\u52A0\n\ntemplate <class S, class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)()> struct dual_segtree {\npublic:\n    dual_segtree()\
    \ : dual_segtree(0) {}\n    explicit dual_segtree(int n) : dual_segtree(vector<S>(n,\
    \ S{})) {}\n    explicit dual_segtree(const vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while((1U << log) < (unsigned int)(_n)) log++;\n\
    \        _size = 1 << log;\n        d = vector<S>(2 * _size);\n        lz = vector<F>(_size,\
    \ id());\n        for(int i = 0; i < _n; i++) d[_size + i] = v[i];\n    }\n\n\
    \    size_t size() const { return _n; }\n\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(p >> i);\n        d[p] = x;\n    }\n\n    void add(int p, S\
    \ x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] += x;\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    void\
    \ apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p += _size;\n\
    \        for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f,\
    \ d[p]);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if(l == r) return;\n\n        l += _size;\n   \
    \     r += _size;\n\n        for(int i = log; i >= 1; i--) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n     \
    \       while(l < r) {\n                if(l & 1) all_apply(l++, f);\n       \
    \         if(r & 1) all_apply(--r, f);\n                l >>= 1;\n           \
    \     r >>= 1;\n            }\n            l = l2;\n            r = r2;\n    \
    \    }\n    }\n\nprivate:\n    int _n, _size, log;\n    vector<S> d;\n    vector<F>\
    \ lz;\n\n    void all_apply(int k, F f) {\n        if(k >= _size) d[k] = mapping(f,\
    \ d[k]);\n        if(k < _size) lz[k] = composition(f, lz[k]);\n    }\n    void\
    \ push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1,\
    \ lz[k]);\n        lz[k] = id();\n    }\n};\n\n\ntemplate <class S, class F> struct\
    \ RangeSet_PointGet {\n    static S mapping(F f, S x) { return (f == id() ? x\
    \ : f); }\n    static F composition(F f, F g) { return (f == id() ? g : f); }\n\
    \    static F id() { return numeric_limits<F>::max(); }\n    using Type = struct\
    \ dual_segtree<S, F, mapping, composition, id>;\n};\ntemplate <class S, class\
    \ F> struct RangeAdd_PointGet {\n    static S mapping(F f, S x) { return f + x;\
    \ }\n    static F composition(F f, F g) { return f + g; }\n    static F id() {\
    \ return 0; }\n    using Type = struct dual_segtree<S, F, mapping, composition,\
    \ id>;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/segtree/dual_segtree.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segtree/dual_segtree.hpp
layout: document
redirect_from:
- /library/lib/segtree/dual_segtree.hpp
- /library/lib/segtree/dual_segtree.hpp.html
title: lib/segtree/dual_segtree.hpp
---
