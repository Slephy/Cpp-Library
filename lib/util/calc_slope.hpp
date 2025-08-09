#pragma once
#include "../core/core.hpp"

// return the slope of the line segment (x1, y1) to (x2, y2) in (dx, dy) format
// dx >= 0 and dy can be negative
template <integral T> pair<T, T> calc_slope(T x1, T y1, T x2, T y2) {
    T dx = x2 - x1;
    T dy = y2 - y1;
    if(dx == 0) return {0, 1};
    if(dy == 0) return {1, 0};

    if(dx < 0) dx = -dx, dy = -dy;
    T g = gcd(dx, dy);
    return {dx / g, dy / g};
}
