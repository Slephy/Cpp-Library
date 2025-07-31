#pragma once
#include "../core/core.hpp"
template <class T, T (*op)(T, T)> class SWAG {
    stack<T> prod_front, prod_back, val_back;

public:
    bool empty() const { return prod_front.empty() && prod_back.empty(); }
    size_t size() const { return prod_front.size() + prod_back.size(); }

    void push(const T &x) {
        val_back.emplace(x);
        if(prod_back.empty()) prod_back.emplace(x);
        else prod_back.emplace(op(prod_back.top(), x));
    }

    void pop() {
        assert(!empty());
        if(prod_front.empty()) {
            while(!val_back.empty()) {
                if(prod_front.empty()) prod_front.emplace(val_back.top());
                else prod_front.emplace(op(val_back.top(), prod_front.top()));
                prod_back.pop(), val_back.pop();
            }
        }
        prod_front.pop();
    }

    T fold_all() {
        assert(!empty());
        if(prod_front.empty()) return prod_back.top();
        else if(prod_back.empty()) return prod_front.top();
        else return op(prod_front.top(), prod_back.top());
    }
};
