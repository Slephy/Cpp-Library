#pragma once
// 三分探索
// 狭義単調性を持つ単峰関数について最小値を取るときの引数を求める
// @need left <= right
template <class Evaluate>
double ternary_search_float(double left, double right,
                            Evaluate eval,  // param: double, return: any
                            double tolerance,
                            bool is_downward = true,  // 下に凸かどうか
                            bool considerRelativeError = true) {
    assert(left <= right);
    auto need_continue = [&]() -> bool {
        if((fabs(left - right) < tolerance)) return false;  // 絶対誤差
        if(considerRelativeError && (fabs(left - right) < tolerance * fabs((left + right) * 0.5)))
            return false;  // 相対誤差
        return true;
    };

    while(need_continue()) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;

        if(is_downward) {
            if(eval(mid1) < eval(mid2)) right = mid2;
            else left = mid1;
        }
        else {
            if(eval(mid1) > eval(mid2)) right = mid2;
            else left = mid1;
        }
    }

    if(is_downward) {
        return (eval(left) < eval(right)) ? left : right;
    }
    else {
        return (eval(left) > eval(right)) ? left : right;
    }
}
