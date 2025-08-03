#pragma once
#include "../core/core.hpp"
namespace atcoder {
namespace internal {
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if(x < 0) x += m;
    return x;
}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
        unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
        unsigned int v = (unsigned int)(z - x * _m);
        if(_m <= v) v += _m;
        return v;
    }
};
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if(m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while(n) {
        if(n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 7 || n == 61) return true;
    if(n % 2 == 0) return false;
    long long d = n - 1;
    while(d % 2 == 0) d /= 2;
    for(long long a : {2, 7, 61}) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if(y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if(a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while(t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if(m0 < 0) m0 += b / s;
    return {s, m0};
}


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T, __int128>::value, std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value || std::is_same<T, unsigned __int128>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;
template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
}  // namespace internal
template <int m, std::enable_if_t<(1 <= m)>* = nullptr> struct static_modint {
    using mint = static_modint;

public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr> static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if(x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr> static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }
    unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if(_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if(_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if(_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if(_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if(prime) {
            assert(_v);
            return pow(umod() - 2);
        }
        else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

    friend istream& operator>>(istream& i, mint& a) {
        long long v;
        i >> v;
        a = v;
        return i;
    }
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val(); }

private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
}  // namespace atcoder
