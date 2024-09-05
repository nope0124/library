#pragma once

#include <vector>
#include "graph_template.hpp"

/**
 * @brief Functional Graph Cycle Detection (Functional Graphのサイクル検出)
 */
template<class T> struct FunctionalGraphCycleDetection {
    int n;
    Graph<T> graph;
    std::vector<bool> reached, finished;
    std::vector<T> history;

    FunctionalGraphCycleDetection(Graph<T> &graph) : n((int)(graph.size())), graph(graph), reached(n, false), finished(n, false) {
        for (int i = 0; i < n; i++) assert ((int)(graph[i].size()) == 1);
    }

    /**
     * @param 頂点vから探索開始
     * @return サイクルの開始頂点
     */
    int search(int v) {
        do {
            reached[v] = true;
            history.push_back(v);
            v = graph[v][0];
            // ぐるぐるサイクルを回る = finishedに辿り着かない
            if (finished[v]) {
                v = -1;
                break;
            }
        } while (!reached[v]);

        // historyを取り出しながらfinishedを埋める
        while (!history.empty()) {
            int v = history.back();
            finished[v] = true;
            history.pop_back();
        }
        return v;
    }

    /**
     * @brief 頂点posからサイクルを構築
     */
    std::vector<T> reconstruct(int pos) {
        std::vector<T> cycle;
        int v = pos;
        do {
            cycle.push_back(v);
            v = graph[v][0];
        } while (v != pos);
        return cycle;
    }

    /**
     * @brief 全てのサイクルを列挙
     */
    std::vector<std::vector<T>> detect_all() {
        std::vector<std::vector<T>> res;
        for (int v = 0; v < (int)(graph.size()); v++) {
            if (finished[v]) continue;
            int pos = search(v);
            if (pos == -1) continue;
            std::vector<T> cycle = reconstruct(pos);
            if (!cycle.empty()) res.push_back(cycle);
        }
        return res;
    }
};