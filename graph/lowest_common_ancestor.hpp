#pragma once

#include <vector>
#include "graph_template.hpp"

/**
 * @brief Lowest Common Ancestor (最小共通祖先)
 */
template<class T> struct LowestCommonAncestor {
    int n;
    const int MAX_DOUBLING = 40;
    std::vector<int> depth;
    std::vector<std::vector<int>> parents;
    
    LowestCommonAncestor(Graph<T> &graph, const int root = 0) : n((int)(graph.size())), depth(n, 0), parents(MAX_DOUBLING, std::vector<int>(n)) {
        auto dfs = [&](auto f, int v, int p, int d) -> void {
            parents[0][v] = p; // 2^0遡るとpに到達
            depth[v] = d; // ルートからの深さ
            for (auto c: graph[v]) {
                if (c != p) f(f, c, v, d + 1);
            }
        };

        dfs(dfs, root, -1, 0); // parents[0]とdepthの初期化を行う

        // ダブリングで2^i遡った際の先祖の値を調べる
        for (int d = 0; d < MAX_DOUBLING - 1; d++) {
            for (int i = 0; i < n; i++) {
                if (parents[d][i] < 0) parents[d + 1][i] = -1;
                else parents[d + 1][i] = parents[d][parents[d][i]];
            }
        }
    }

    /**
     * @brief 二頂点の最小共通祖先を調べる
     * @param u 頂点1
     * @param v 頂点2
     * @return 最小共通祖先
     */
    int lca(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v); // u < v、vの方が深い状態にする
        for (int d = 0; d < MAX_DOUBLING; d++) {
            if((long long int)(depth[v] - depth[u]) >> d & 1) {
                v = parents[d][v]; // 深さを合わせる
            }
        }
        // この時点で一致したらそれが最小共通祖先
        if (u == v) return u;
        for (int d = MAX_DOUBLING - 1; d >= 0; d--){
            if (parents[d][u] != parents[d][v]) {
                u = parents[d][u];
                v = parents[d][v];
            }
        }
        return parents[0][u];
    }

    /**
     * @brief 二頂点の最短距離を調べる
     * @param u 頂点1
     * @param v 頂点2
     * @return 最短距離
     */
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};