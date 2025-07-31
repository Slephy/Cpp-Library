#pragma once
#include "../core/core.hpp"
// from : https://naskya.net/post/0004/
#include <chrono>
namespace utility {
struct Timer {
private:
    const std::chrono::system_clock::time_point start;

public:
    const unsigned TIME_LIMIT;  // ms

    // time_limit[ms]
    Timer(unsigned time_limit = 2000 - 50) noexcept : TIME_LIMIT(time_limit), start(std::chrono::system_clock::now()) {}

    // 経過時間 (ms) を返す
    [[nodiscard]] auto elapsed() const {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now() - start).count();
    }

    // 経過時間の割合を返す
    [[nodiscard]] double elapsed_ratio() const { return elapsed() / static_cast<double>(TIME_LIMIT); }

    // 経過時間が制限時間の nume/deno 倍未満かを返す
    // 例えば frac<1, 2>() は経過時間が制限時間の 1/2 未満かを返す
    template <unsigned nume, unsigned deno> [[nodiscard]] bool frac() const {
        return elapsed() * deno < TIME_LIMIT * nume;
    }

    // 経過時間が制限時間未満かを返す
    [[nodiscard]] bool good() const { return elapsed() < TIME_LIMIT; }
};
}  // namespace utility
