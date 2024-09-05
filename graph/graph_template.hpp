#pragma once

#include <vector>

/**
 * @brief グラフテンプレート
 */
template<class T> struct Edge {
    int from;
    int to;
    T cost;

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<class T> struct Graph {
    int n;
    std::vector<std::vector<T>> graph;

    Graph(int n) : n(n), graph(n, std::vector<T>()) {}
    inline std::vector<T>& operator[] (int i) { return graph[i]; }
    size_t size() const { return graph.size(); }

    std::vector<int> preorder, postorder;

    /**
     * @brief 行きがけ順、帰りがけ順の配列を作る
     */
    void calculateOrder() {
        std::vector<bool> reached(n, false);
        auto dfs = [&](auto f, int v, int p) -> void {
            if (reached[v]) return;
            reached[v] = true;
            preorder.push_back(v);
            for (auto c: graph[v]) {
                if (c == p) continue;
                f(f, c, v);
            }
            postorder.push_back(v);
            return;
        };

        for (int i = 0; i < n; i++) if (!reached[i]) dfs(dfs, i, -1);

        assert((int)(preorder.size()) == n);
        assert((int)(postorder.size()) == n);
    }
};
