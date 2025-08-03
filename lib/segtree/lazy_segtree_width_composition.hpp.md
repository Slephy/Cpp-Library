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
    \ 3 \"lib/segtree/lazy_segtree_width_composition.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\
    \u3092\u4E00\u90E8\u6539\u5909\u3057\u305F\u3082\u306E\n// composition \u306E\u7B2C\
    \u4E09\u5F15\u6570\u3068\u3057\u3066\u533A\u9593\u5E45\u3092\u8FFD\u52A0\n// \u3053\
    \u308C\u306B\u3088\u308A\u533A\u9593\u548C\u3092\u53D6\u5F97\u3059\u308B\u3068\
    \u304D\u306E\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u304C\u7C21\u6F54\
    \u306B\u306A\u308B\n// \u4F5C\u7528\u304C\u533A\u9593\u5E45\u3092\u5229\u7528\u3059\
    \u308B\u3088\u3046\u306A\u5834\u5408\u306B\u4F7F\u3046\uFF08\u305D\u308C\u4EE5\
    \u5916\u306E\u3068\u304D\u306B\u306F\u901A\u5E38\u306E\u9045\u5EF6\u30BB\u30B0\
    \u6728\u3092\u4F7F\u3063\u305F\u65B9\u304C\u5B9A\u6570\u500D\u304C\u826F\u3044\
    \uFF09\n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2 \u3092\u57CB\u3081\
    \u8FBC\u307F\n// add \u95A2\u6570\u3092\u8FFD\u52A0\n// size \u95A2\u6570\u3092\
    \u8FFD\u52A0\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F,\
    \ S, ll), F (*composition)(F, F), F (*id)()>\nstruct lazy_segtree_width_composition\
    \ {\npublic:\n    lazy_segtree_width_composition() : lazy_segtree_width_composition(0)\
    \ {}\n    explicit lazy_segtree_width_composition(int n) : lazy_segtree_width_composition(vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree_width_composition(const vector<S>& v) :\
    \ _n(int(v.size())) {\n        log = 0;\n        while((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        _size = 1 << log;\n        d = vector<S>(2 * _size,\
    \ e());\n        lz = vector<F>(_size, id());\n        width = vector<int>(2 *\
    \ _size, 1);\n        for(int i = 0; i < _n; i++) {\n            d[_size + i]\
    \ = v[i];\n            width[_size + i] = 1;\n        }\n        for(int i = _size\
    \ - 1; i >= 1; i--) {\n            update(i);\n            width[i] = width[2\
    \ * i] + width[2 * i + 1];\n        }\n    }\n\n    size_t size() const { return\
    \ _n; }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n   \
    \     p += _size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n     \
    \   d[p] = x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
    \    void add(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n\
    \        for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] += x;\n   \
    \     for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r)\
    \ return e();\n\n        l += _size;\n        r += _size;\n\n        for(int i\
    \ = log; i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n\
    \            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n     \
    \   S sml = e(), smr = e();\n        while(l < r) {\n            if(l & 1) sml\
    \ = op(sml, d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n         \
    \   l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p], width[p]);\n   \
    \     for(int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l\
    \ == r) return;\n\n        l += _size;\n        r += _size;\n\n        for(int\
    \ i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n\
    \            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n     \
    \   {\n            int l2 = l, r2 = r;\n            while(l < r) {\n         \
    \       if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for(int i = 1; i\
    \ <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n     \
    \       if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n \
    \   template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if(l == _n) return _n;\n        l += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while(l\
    \ % 2 == 0) l >>= 1;\n            if(!g(op(sm, d[l]))) {\n                while(l\
    \ < _size) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if(g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - _size;\n            }\n            sm = op(sm,\
    \ d[l]);\n            l++;\n        } while((l & -l) != l);\n        return _n;\n\
    \    }\n\n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if(r == 0) return 0;\n        r += _size;\n        for(int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while(r > 1 && (r % 2)) r >>= 1;\n            if(!g(op(d[r], sm)))\
    \ {\n                while(r < _size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if(g(op(d[r], sm))) {\n \
    \                       sm = op(d[r], sm);\n                        r--;\n   \
    \                 }\n                }\n                return r + 1 - _size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while((r & -r) != r);\n\
    \        return 0;\n    }\n\n    friend ostream& operator<<(ostream& os, lazy_segtree_width_composition&\
    \ seg) {\n        os << \"[\";\n        for(int i = 0; i < seg._n; i++) {\n  \
    \          if(i != 0) os << \", \";\n            os << seg.get(i);\n        }\n\
    \        os << \"]\";\n        return os;\n    }\n\nprivate:\n    int _n, _size,\
    \ log;\n    vector<S> d;\n    vector<F> lz;\n    vector<int> width;  // width[i]\
    \ := d[i], lz[i] \u304C\u62C5\u5F53\u3059\u308B\u533A\u9593\u306E\u5E45\n\n  \
    \  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int\
    \ k, F f) {\n        d[k] = mapping(f, d[k], width[k]);\n        if(k < _size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n\ntemplate <class S, class F> struct RangeAdd_RangeSum {\n    static\
    \ S op(S a, S b) { return a + b; }\n    static S e() { return 0; }\n    static\
    \ S mapping(F f, S x, ll width) { return x + f * width; }\n    static F composition(F\
    \ f, F g) { return f + g; }\n    static F id() { return 0; }\n    using Type =\
    \ struct lazy_segtree_width_composition<S, op, e, F, mapping, composition, id>;\n\
    };\ntemplate <class S, class F> struct RangeSet_RangeSum {\n    static S op(S\
    \ a, S b) { return a + b; }\n    static S e() { return 0; }\n    static S mapping(F\
    \ f, S x, ll width) { return (f == id() ? x : f * width); }\n    static F composition(F\
    \ f, F g) { return (f == id() ? g : f); }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    using Type = struct lazy_segtree_width_composition<S, op, e, F, mapping,\
    \ composition, id>;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\u3092\
    \u4E00\u90E8\u6539\u5909\u3057\u305F\u3082\u306E\n// composition \u306E\u7B2C\u4E09\
    \u5F15\u6570\u3068\u3057\u3066\u533A\u9593\u5E45\u3092\u8FFD\u52A0\n// \u3053\u308C\
    \u306B\u3088\u308A\u533A\u9593\u548C\u3092\u53D6\u5F97\u3059\u308B\u3068\u304D\
    \u306E\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u304C\u7C21\u6F54\u306B\
    \u306A\u308B\n// \u4F5C\u7528\u304C\u533A\u9593\u5E45\u3092\u5229\u7528\u3059\u308B\
    \u3088\u3046\u306A\u5834\u5408\u306B\u4F7F\u3046\uFF08\u305D\u308C\u4EE5\u5916\
    \u306E\u3068\u304D\u306B\u306F\u901A\u5E38\u306E\u9045\u5EF6\u30BB\u30B0\u6728\
    \u3092\u4F7F\u3063\u305F\u65B9\u304C\u5B9A\u6570\u500D\u304C\u826F\u3044\uFF09\
    \n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2 \u3092\u57CB\u3081\u8FBC\
    \u307F\n// add \u95A2\u6570\u3092\u8FFD\u52A0\n// size \u95A2\u6570\u3092\u8FFD\
    \u52A0\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F,\
    \ S, ll), F (*composition)(F, F), F (*id)()>\nstruct lazy_segtree_width_composition\
    \ {\npublic:\n    lazy_segtree_width_composition() : lazy_segtree_width_composition(0)\
    \ {}\n    explicit lazy_segtree_width_composition(int n) : lazy_segtree_width_composition(vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree_width_composition(const vector<S>& v) :\
    \ _n(int(v.size())) {\n        log = 0;\n        while((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        _size = 1 << log;\n        d = vector<S>(2 * _size,\
    \ e());\n        lz = vector<F>(_size, id());\n        width = vector<int>(2 *\
    \ _size, 1);\n        for(int i = 0; i < _n; i++) {\n            d[_size + i]\
    \ = v[i];\n            width[_size + i] = 1;\n        }\n        for(int i = _size\
    \ - 1; i >= 1; i--) {\n            update(i);\n            width[i] = width[2\
    \ * i] + width[2 * i + 1];\n        }\n    }\n\n    size_t size() const { return\
    \ _n; }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n   \
    \     p += _size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n     \
    \   d[p] = x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
    \    void add(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n\
    \        for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] += x;\n   \
    \     for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r)\
    \ return e();\n\n        l += _size;\n        r += _size;\n\n        for(int i\
    \ = log; i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n\
    \            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n     \
    \   S sml = e(), smr = e();\n        while(l < r) {\n            if(l & 1) sml\
    \ = op(sml, d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n         \
    \   l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p], width[p]);\n   \
    \     for(int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l\
    \ == r) return;\n\n        l += _size;\n        r += _size;\n\n        for(int\
    \ i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n\
    \            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n     \
    \   {\n            int l2 = l, r2 = r;\n            while(l < r) {\n         \
    \       if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for(int i = 1; i\
    \ <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n     \
    \       if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n \
    \   template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if(l == _n) return _n;\n        l += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while(l\
    \ % 2 == 0) l >>= 1;\n            if(!g(op(sm, d[l]))) {\n                while(l\
    \ < _size) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if(g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - _size;\n            }\n            sm = op(sm,\
    \ d[l]);\n            l++;\n        } while((l & -l) != l);\n        return _n;\n\
    \    }\n\n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if(r == 0) return 0;\n        r += _size;\n        for(int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while(r > 1 && (r % 2)) r >>= 1;\n            if(!g(op(d[r], sm)))\
    \ {\n                while(r < _size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if(g(op(d[r], sm))) {\n \
    \                       sm = op(d[r], sm);\n                        r--;\n   \
    \                 }\n                }\n                return r + 1 - _size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while((r & -r) != r);\n\
    \        return 0;\n    }\n\n    friend ostream& operator<<(ostream& os, lazy_segtree_width_composition&\
    \ seg) {\n        os << \"[\";\n        for(int i = 0; i < seg._n; i++) {\n  \
    \          if(i != 0) os << \", \";\n            os << seg.get(i);\n        }\n\
    \        os << \"]\";\n        return os;\n    }\n\nprivate:\n    int _n, _size,\
    \ log;\n    vector<S> d;\n    vector<F> lz;\n    vector<int> width;  // width[i]\
    \ := d[i], lz[i] \u304C\u62C5\u5F53\u3059\u308B\u533A\u9593\u306E\u5E45\n\n  \
    \  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int\
    \ k, F f) {\n        d[k] = mapping(f, d[k], width[k]);\n        if(k < _size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n\ntemplate <class S, class F> struct RangeAdd_RangeSum {\n    static\
    \ S op(S a, S b) { return a + b; }\n    static S e() { return 0; }\n    static\
    \ S mapping(F f, S x, ll width) { return x + f * width; }\n    static F composition(F\
    \ f, F g) { return f + g; }\n    static F id() { return 0; }\n    using Type =\
    \ struct lazy_segtree_width_composition<S, op, e, F, mapping, composition, id>;\n\
    };\ntemplate <class S, class F> struct RangeSet_RangeSum {\n    static S op(S\
    \ a, S b) { return a + b; }\n    static S e() { return 0; }\n    static S mapping(F\
    \ f, S x, ll width) { return (f == id() ? x : f * width); }\n    static F composition(F\
    \ f, F g) { return (f == id() ? g : f); }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    using Type = struct lazy_segtree_width_composition<S, op, e, F, mapping,\
    \ composition, id>;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/segtree/lazy_segtree_width_composition.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segtree/lazy_segtree_width_composition.hpp
layout: document
redirect_from:
- /library/lib/segtree/lazy_segtree_width_composition.hpp
- /library/lib/segtree/lazy_segtree_width_composition.hpp.html
title: lib/segtree/lazy_segtree_width_composition.hpp
---
