#pragma once
#include "../core/core.hpp"

vector<double> solve_quadratic_float(double a, double b, double c) {
    assert(a != 0 || b != 0 || c != 0);
    if(a == 0) {
        if(b == 0) return {};
        else return vector<double>{-c / b};
    }

    vector<double> ret;
    double d = b * b - 4 * a * c;
    if(abs(d) <= 1e-10) {
        ret.push_back(-b / (2 * a));
        return ret;
    }
    else if(d < 0) return ret;
    else {
        double sq = sqrt(d);
        ret.emplace_back((-b + sq) / (2 * a));
        ret.emplace_back((-b - sq) / (2 * a));
        return ret;
    }
}
