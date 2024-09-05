#pragma once

#include <vector>
#include "graph_template.hpp"

/**
 * @brief Functional Graph Cycle Detection (Functional Graphのサイクル検出)
 */
template<class T> struct FunctionalGraphCycleDetection {
    int n;
    bool is_directed;
    Graph<T> graph;
    std::vector<bool> reached, finished, in_cycle;
    std::vector<T> history;

    FunctionalGraphCycleDetection(Graph<T> &graph, bool is_directed) : n((int)(graph.size())), is_directed(is_directed), graph(graph), reached(n, false), finished(n, false), in_cycle(n, true) {
        if (is_directed) for (int i = 0; i < n; i++) assert ((int)(graph[i].size()) == 1);
        build();
    }

    /**
     * @brief in_cycleを構築する
     */
    void build() {
        std::queue<int> que;
        std::vector<int> deg(n, 0);
        int target = !is_directed;
        for (int i = 0; i < n; i++) for (auto c: graph[i]) deg[c]++;
        for (int i = 0; i < n; i++) {
            if (deg[i] == target) {
                que.push(i);
                in_cycle[i] = false;
            }
        }
        while (!que.empty()) {
            auto v = que.front(); que.pop();
            for (auto c: graph[v]) {
                if (!in_cycle[c]) continue;
                deg[c]--;
                if (deg[c] == target) {
                    in_cycle[c] = false;
                    que.push(c);
                }
            }
        }
        return;
    }

    /**
     * @brief 頂点posからサイクルを構築
     */
    std::vector<T> reconstruct(int pos) {
        std::vector<T> cycle;
        int v = pos;
        int parent = -1;
        do {
            cycle.push_back(v);
            reached[v] = true;
            for (auto c: graph[v]) {
                if (c == parent) continue;
                if (!in_cycle[c]) continue;
                v = c;
                parent = v;
                break;
            }
        } while (v != pos);
        return cycle;
    }

    /**
     * @brief 全てのサイクルを列挙
     */
    std::vector<std::vector<T>> detect_all() {
        std::vector<std::vector<T>> res;
        for (int v = 0; v < (int)(graph.size()); v++) {
            if (!in_cycle[v] || reached[v]) continue;
            std::vector<T> cycle = reconstruct(v);
            if (!cycle.empty()) res.push_back(cycle);
            else assert(false);
        }
        return res;
    }
};