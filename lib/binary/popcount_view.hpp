#pragma once
#include "../core/core.hpp"
// 長さが length で、1 の数が count 個のビット列に対応する整数を列挙する
class PopcountView {
public:
    PopcountView(size_t length, size_t count)
        : begin_((1LL << count) - 1), end_(numeric_limits<ll>::max()), inf((1LL << length)) {
        assert(count <= length);
    }

    class Iterator {
    public:
        Iterator(ll value, ll inf) : value(value), inf(inf) {}
        ll& operator*() { return value; }
        Iterator& operator++() {
            if(value == 0) {
                value = numeric_limits<ll>::max();
                return *this;
            }
            else {
                ll x = value & -value, y = value + x;
                value = ((value & ~y) / x >> 1) | y;
                if(value >= inf) value = numeric_limits<ll>::max();
                return *this;
            }
        }
        bool operator==(const Iterator& other) const { return value == other.value; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }

    private:
        ll value, inf;
    };

    Iterator begin() const { return Iterator(begin_, inf); }
    Iterator end() const { return Iterator(end_, inf); }

private:
    ll begin_, end_, inf;
};
