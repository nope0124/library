#pragma once

#include <vector>

template<class T> struct Graph {
    std::vector<std::vector<T>> graph;

    Graph(int n) : graph(n, std::vector<T>()) {}
    inline std::vector<T>& operator[] (int i) { return graph[i]; }
    size_t size() const { return graph.size(); }
};
