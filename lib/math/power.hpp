#pragma once
#include "../core/core.hpp"

template <typename T>
concept HasPowMember = requires(T a, ll b) {
    { a.pow(b) };
};

template <HasPowMember T>
T pow(T val, ll exp){
    return val.pow(exp);
}
