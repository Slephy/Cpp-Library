#pragma once
#include "../core/core.hpp"

struct Edge {
    int to;
    Edge() = default;
    Edge(int to) : to(to) {}
    operator int() const { return to; }
};

template <class T> struct WeightedEdge : public Edge {
    T weight;
};
