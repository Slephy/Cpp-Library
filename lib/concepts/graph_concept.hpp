#pragma once
#include "../core/core.hpp"
template <typename T>
concept AdjListGraph = std::convertible_to<typename T::value_type::value_type, int>;

template <typename T>
concept AdjListWeightedGraph = requires(T graph) {
    requires AdjListGraph<T>;
    requires requires(typename T::value_type::value_type edge) {
        { edge.to } -> std::convertible_to<int>;
        edge.weight;
    };
};
