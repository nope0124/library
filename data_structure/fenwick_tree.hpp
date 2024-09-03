#pragma once

#include <vector>

template<class T> struct FenwickTree {
    private:
    int n;
    std::vector<int> bit;

    public:
    FenwickTree(int n) : n(n), bit(n + 1, T(0)) {}
    FenwickTree(std::vector<T>& V) : n((int)(V.size())), bit(n + 1, T(0)) {
        for (int i = 0; i < n; i++) add(i, V[i]);
    }

    // 0-indexedで値を追加
    // V[idx] += x
    void add(int idx, T x) {
        assert(0 <= idx && idx < n);
        idx++; // 1-indexedにする
        assert(1 <= idx && idx <= n);
        while (idx <= n) {
            bit[idx] += x;
            idx += (idx & -idx);
        }
    }

    // V[0, idx)の和を取得
    T getSum(int idx) {
        assert(0 <= idx && idx <= n);
        T res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    // V[left, right) = V[0, right) - V[0, left)
    T getSum(int left, int right) {
        assert(0 <= left && left <= right && right <= n);
        return getSum(right) - getSum(left);
    }

    // V[idx] = V[idx, idx + 1) = V[0, idx + 1) - V[0, idx)
    T get(int idx) {
        assert(0 <= idx && idx < n);
        return getSum(idx + 1) - getSum(idx);
    }

    // V[idx] = x
    void update(int idx, T x) {
        assert(0 <= idx && idx < n);
        add(idx, x - get(idx));
    }

    std::vector<T> getVector() {
        std::vector<T> V(n);
        for (int i = 0; i < n; i++) V[i] = get(i);
        return V;
    }
};
