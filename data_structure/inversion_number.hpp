#pragma once

#include "data_structure/fenwick_tree.hpp"

/**
 * @brief 転倒数 (Inversion Number)
 */
template<class T> long long inversion_number(std::vector<T>& V) {
    std::vector<T> W = V;
    sort(W.begin(), W.end());
    W.erase(unique(W.begin(), W.end()), W.end());
    int n = (int)(W.size());
    FenwickTree<int> bit(n);
    long long res = 0;
    for (auto v: V) {
        int idx = lower_bound(W.begin(), W.end(), v) - W.begin();
        res += bit.getSum(idx + 1, n);
        bit.add(idx, 1);
    }
    return res;
}
