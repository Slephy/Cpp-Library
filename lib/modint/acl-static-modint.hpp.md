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
    \ 3 \"lib/modint/acl-static-modint.hpp\"\nnamespace atcoder {\nnamespace internal\
    \ {\nconstexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n \
    \   if(x < 0) x += m;\n    return x;\n}\nstruct barrett {\n    unsigned int _m;\n\
    \    unsigned long long im;\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n    unsigned int umod() const { return _m; }\n \
    \   unsigned int mul(unsigned int a, unsigned int b) const {\n        unsigned\
    \ long long z = a;\n        z *= b;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned int v = (unsigned\
    \ int)(z - x * _m);\n        if(_m <= v) v += _m;\n        return v;\n    }\n\
    };\nconstexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n\
    \    if(m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned\
    \ long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n    while(n) {\n\
    \        if(n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>=\
    \ 1;\n    }\n    return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  \
    \  if(n <= 1) return false;\n    if(n == 2 || n == 7 || n == 61) return true;\n\
    \    if(n % 2 == 0) return false;\n    long long d = n - 1;\n    while(d % 2 ==\
    \ 0) d /= 2;\n    for(long long a : {2, 7, 61}) {\n        long long t = d;\n\
    \        long long y = pow_mod_constexpr(a, t, n);\n        while(t != n - 1 &&\
    \ y != 1 && y != n - 1) {\n            y = y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && t % 2 == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool is_prime\
    \ = is_prime_constexpr(n);\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if(a == 0) return {b, 0};\n\
    \    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n    while(t) {\n\
    \        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;  //\
    \ |m1 * u| <= |m1| * s <= b\n        auto tmp = s;\n        s = t;\n        t\
    \ = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if(m0\
    \ < 0) m0 += b / s;\n    return {s, m0};\n}\n\n\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T,\
    \ __int128>::value, std::true_type,\n                              std::false_type>::type;\n\
    template <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value,\n        \
    \                      std::true_type, std::false_type>::type;\ntemplate <class\
    \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\ntemplate <class T>\nusing\
    \ is_signed_int =\n    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value)\
    \ || is_signed_int128<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\ntemplate <class T>\nusing is_unsigned_int =\n    typename\
    \ std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value,\n\
    \                              std::true_type, std::false_type>::type;\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\ntemplate <class T>\
    \ using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\ntemplate\
    \ <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    }  // namespace internal\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\
    \ struct static_modint {\n    using mint = static_modint;\n\npublic:\n    static\
    \ constexpr int mod() { return m; }\n    static mint raw(int v) {\n        mint\
    \ x;\n        x._v = v;\n        return x;\n    }\n    static_modint() : _v(0)\
    \ {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr> static_modint(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if(x\
    \ < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr> static_modint(T v) {\n       \
    \ _v = (unsigned int)(v % umod());\n    }\n    static_modint(bool v) { _v = ((unsigned\
    \ int)(v) % umod()); }\n    unsigned int val() const { return _v; }\n    mint&\
    \ operator++() {\n        _v++;\n        if(_v == umod()) _v = 0;\n        return\
    \ *this;\n    }\n    mint& operator--() {\n        if(_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n    mint operator++(int) {\n   \
    \     mint result = *this;\n        ++*this;\n        return result;\n    }\n\
    \    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n    mint& operator+=(const mint& rhs) {\n    \
    \    _v += rhs._v;\n        if(_v >= umod()) _v -= umod();\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n     \
    \   if(_v >= umod()) _v += umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n   \
    \     _v = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n    mint\
    \ operator+() const { return *this; }\n    mint operator-() const { return mint()\
    \ - *this; }\n    mint pow(long long n) const {\n        assert(0 <= n);\n   \
    \     mint x = *this, r = 1;\n        while(n) {\n            if(n & 1) r *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return r;\n   \
    \ }\n    mint inv() const {\n        if(prime) {\n            assert(_v);\n  \
    \          return pow(umod() - 2);\n        }\n        else {\n            auto\
    \ eg = internal::inv_gcd(_v, m);\n            assert(eg.first == 1);\n       \
    \     return eg.second;\n        }\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend istream&\
    \ operator>>(istream& i, mint& a) {\n        long long v;\n        i >> v;\n \
    \       a = v;\n        return i;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.val(); }\n\nprivate:\n    unsigned int _v;\n\
    \    static constexpr unsigned int umod() { return m; }\n    static constexpr\
    \ bool prime = internal::is_prime<m>;\n};\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\n}  // namespace atcoder\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\nnamespace atcoder {\nnamespace\
    \ internal {\nconstexpr long long safe_mod(long long x, long long m) {\n    x\
    \ %= m;\n    if(x < 0) x += m;\n    return x;\n}\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n    unsigned int umod() const { return _m; }\n \
    \   unsigned int mul(unsigned int a, unsigned int b) const {\n        unsigned\
    \ long long z = a;\n        z *= b;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned int v = (unsigned\
    \ int)(z - x * _m);\n        if(_m <= v) v += _m;\n        return v;\n    }\n\
    };\nconstexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n\
    \    if(m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned\
    \ long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n    while(n) {\n\
    \        if(n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>=\
    \ 1;\n    }\n    return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  \
    \  if(n <= 1) return false;\n    if(n == 2 || n == 7 || n == 61) return true;\n\
    \    if(n % 2 == 0) return false;\n    long long d = n - 1;\n    while(d % 2 ==\
    \ 0) d /= 2;\n    for(long long a : {2, 7, 61}) {\n        long long t = d;\n\
    \        long long y = pow_mod_constexpr(a, t, n);\n        while(t != n - 1 &&\
    \ y != 1 && y != n - 1) {\n            y = y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && t % 2 == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\ntemplate <int n> constexpr bool is_prime\
    \ = is_prime_constexpr(n);\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if(a == 0) return {b, 0};\n\
    \    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n    while(t) {\n\
    \        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;  //\
    \ |m1 * u| <= |m1| * s <= b\n        auto tmp = s;\n        s = t;\n        t\
    \ = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if(m0\
    \ < 0) m0 += b / s;\n    return {s, m0};\n}\n\n\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T,\
    \ __int128>::value, std::true_type,\n                              std::false_type>::type;\n\
    template <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value,\n        \
    \                      std::true_type, std::false_type>::type;\ntemplate <class\
    \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\ntemplate <class T>\nusing\
    \ is_signed_int =\n    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value)\
    \ || is_signed_int128<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\ntemplate <class T>\nusing is_unsigned_int =\n    typename\
    \ std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value,\n\
    \                              std::true_type, std::false_type>::type;\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\ntemplate <class T>\
    \ using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\ntemplate\
    \ <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    }  // namespace internal\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\
    \ struct static_modint {\n    using mint = static_modint;\n\npublic:\n    static\
    \ constexpr int mod() { return m; }\n    static mint raw(int v) {\n        mint\
    \ x;\n        x._v = v;\n        return x;\n    }\n    static_modint() : _v(0)\
    \ {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr> static_modint(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if(x\
    \ < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr> static_modint(T v) {\n       \
    \ _v = (unsigned int)(v % umod());\n    }\n    static_modint(bool v) { _v = ((unsigned\
    \ int)(v) % umod()); }\n    unsigned int val() const { return _v; }\n    mint&\
    \ operator++() {\n        _v++;\n        if(_v == umod()) _v = 0;\n        return\
    \ *this;\n    }\n    mint& operator--() {\n        if(_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n    mint operator++(int) {\n   \
    \     mint result = *this;\n        ++*this;\n        return result;\n    }\n\
    \    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n    mint& operator+=(const mint& rhs) {\n    \
    \    _v += rhs._v;\n        if(_v >= umod()) _v -= umod();\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n     \
    \   if(_v >= umod()) _v += umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n   \
    \     _v = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n    mint\
    \ operator+() const { return *this; }\n    mint operator-() const { return mint()\
    \ - *this; }\n    mint pow(long long n) const {\n        assert(0 <= n);\n   \
    \     mint x = *this, r = 1;\n        while(n) {\n            if(n & 1) r *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return r;\n   \
    \ }\n    mint inv() const {\n        if(prime) {\n            assert(_v);\n  \
    \          return pow(umod() - 2);\n        }\n        else {\n            auto\
    \ eg = internal::inv_gcd(_v, m);\n            assert(eg.first == 1);\n       \
    \     return eg.second;\n        }\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend istream&\
    \ operator>>(istream& i, mint& a) {\n        long long v;\n        i >> v;\n \
    \       a = v;\n        return i;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.val(); }\n\nprivate:\n    unsigned int _v;\n\
    \    static constexpr unsigned int umod() { return m; }\n    static constexpr\
    \ bool prime = internal::is_prime<m>;\n};\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\n}  // namespace atcoder\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/modint/acl-static-modint.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/modint/acl-static-modint.hpp
layout: document
redirect_from:
- /library/lib/modint/acl-static-modint.hpp
- /library/lib/modint/acl-static-modint.hpp.html
title: lib/modint/acl-static-modint.hpp
---
