#pragma once
#include "../core/core.hpp"

template <typename T>
concept IsModint = requires(T a, ll b) {
    { a.pow(b) } -> same_as<T>;
    { a.val() } -> std::convertible_to<ll>;
    { T::mod() } -> std::convertible_to<ll>;
};
