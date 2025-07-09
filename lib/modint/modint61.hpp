#pragma once
#include "../core/core.hpp"

struct modint61 {
    using mint = modint61;
    using i64 = long long;
    using i128 = __int128_t;
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    const static i64 m = (i64)(1LL << 61) - 1;

    static constexpr i64 mod() { return m; }
    static mint raw(i64 v) {
        mint x;
        x._v = v;
        return x;
    }
    modint61() : _v(0) {}
    modint61(i64 v) {
        if(v >= 0) _v = calc_mod(v);
        else if(v >= -m) _v = v + m;
        else {
            i64 x = v % m;
            if(x < 0) x += m;
            _v = x;
        }
    }
    // modint61(bool v) { _v = ((unsigned int)(v) % umod());
    i64 val() const { return _v; }
    mint& operator++() {
        _v++;
        if(_v == m) _v = 0;
        return *this;
    }
    mint& operator--() {
        if(_v == 0) _v = m;
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
        if(_v >= m) _v -= m;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if(_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        u128 z = _v;
        z *= rhs._v;
        _v = calc_mod(z);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1LL;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        assert(_v);
        return pow(m - 2);
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
    u64 calc_mod(u128 x) {
        u64 res = (x >> 61) + (x & m);
        if(res >= m) res -= m;
        return res;
    }
    u64 _v;
    static constexpr u64 umod() { return m; }
};
