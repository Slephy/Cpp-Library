#pragma once
#include <concepts>

template <typename T>
concept GraphConcept = std::convertible_to<typename T::value_type::value_type, int>;

template <typename T>
concept WeightedGraphConcept = requires(T graph) {
    requires GraphConcept<T>;
    requires requires(typename T::value_type::value_type edge) {
        { edge.to } -> std::convertible_to<int>;
        edge.weight;
    };
};

struct Edge {
    int to;
    Edge() = default;
    Edge(int to) : to(to) {}
    operator int() const { return to; }
};

template <class T> struct WeightedEdge : public Edge {
    T weight;
};
