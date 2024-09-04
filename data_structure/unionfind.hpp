#pragma once

#include <vector>

/**
 * @brief Union-Find木
 */
struct UnionFind {
    private:
    std::vector<int> parents;
  
    public:
    UnionFind(int n) : parents(n, -1) { }

    /**
     * @brief parentsを初期化する
     * @param n グラフの頂点数
     */
    void init(int n) { parents.assign(n, -1); }

    /**
     * @brief ある頂点の根を求める
     * @param x 頂点
     * @return その頂点のルート
     */
    int root(int x) {
        if (parents[x] < 0) return x;
        else return parents[x] = root(parents[x]);
    }

    /**
     * @brief 二つの頂点が同じ集団に属しているか
     * @param x 頂点1
     * @param y 頂点2
     * @return 頂点1と頂点2が同じ集団に属していた場合true
     */
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    /**
     * @brief 二つの頂点を結合させる
     * @param x 頂点1
     * @param y 頂点2
     */
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (parents[x] > parents[y]) std::swap(x, y);
        parents[x] += parents[y]; // sizeを調整
        parents[y] = x; // 大きい木の根に小さい木をつける, yの親はx
    }

    /**
     * @brief 頂点の属している集団のサイズ
     * @param x 頂点
     * @return 集団のサイズ
     */
    int size(int x) {
        return -parents[root(x)];
    }
};
