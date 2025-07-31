#pragma once
#include "../core/core.hpp"
struct Point {
    double px, py;
};
Point operator+(const Point &a1, const Point &a2) { return Point{a1.px + a2.px, a1.py + a2.py}; }
Point operator-(const Point &a1, const Point &a2) { return Point{a1.px - a2.px, a1.py - a2.py}; }
bool operator<(const Point &a1, const Point &a2) {
    if(a1.px != a2.px) return a1.px < a2.px;
    else return a1.py < a2.py;
}
istream &operator>>(istream &i, Point &A) {
    i >> A.px >> A.py;
    return i;
}
ostream &operator<<(ostream &o, const Point &A) {
    o << A.px << " " << A.py;
    return o;
}

ll inn(const Point &p1, const Point &p2) { return p1.px * p2.px + p1.py * p2.py; }
ll crs(const Point &p1, const Point &p2) { return p1.px * p2.py - p1.py * p2.px; }
