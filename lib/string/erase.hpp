#pragma once
#include "../core/core.hpp"
#include "./replace.hpp"

namespace slephy {
// O(|s|)
[[nodiscard]] string erase(const string &s, const string &target) { return slephy::replace(s, target, ""); }
};  // namespace slephy
