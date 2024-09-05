---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/functional_graph_cycle_detection.test.cpp
    title: verify/graph/functional_graph_cycle_detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Functional Graph Cycle Detection (Functional Graph\u306E\u30B5\
      \u30A4\u30AF\u30EB\u691C\u51FA)"
    links: []
  bundledCode: "#line 2 \"graph/functional_graph_cycle_detection.hpp\"\n\n#include\
    \ <vector>\n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\
    \n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\
    template<class T> struct Edge {\n    int from;\n    int to;\n    T cost;\n\n \
    \   Edge(int from = -1, int to = -1, T cost = -1) : from(from), to(to), cost(cost)\
    \ {}\n};\n\ntemplate<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
    \ graph;\n\n    Graph(int n) : n(n), graph(n, std::vector<T>()) {}\n    inline\
    \ std::vector<T>& operator[] (int i) { return graph[i]; }\n    size_t size() const\
    \ { return graph.size(); }\n\n    std::vector<int> preorder, postorder;\n\n  \
    \  /**\n     * @brief \u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\
    \u9806\u306E\u914D\u5217\u3092\u4F5C\u308B\n     */\n    void calculateOrder()\
    \ {\n        std::vector<bool> reached(n, false);\n        auto dfs = [&](auto\
    \ f, int v, int p) -> void {\n            if (reached[v]) return;\n          \
    \  reached[v] = true;\n            preorder.push_back(v);\n            for (auto\
    \ c: graph[v]) {\n                if (c == p) continue;\n                f(f,\
    \ c, v);\n            }\n            postorder.push_back(v);\n            return;\n\
    \        };\n\n        for (int i = 0; i < n; i++) if (!reached[i]) dfs(dfs, i,\
    \ -1);\n\n        assert((int)(preorder.size()) == n);\n        assert((int)(postorder.size())\
    \ == n);\n    }\n};\n#line 5 \"graph/functional_graph_cycle_detection.hpp\"\n\n\
    /**\n * @brief Functional Graph Cycle Detection (Functional Graph\u306E\u30B5\u30A4\
    \u30AF\u30EB\u691C\u51FA)\n */\ntemplate<class T> struct FunctionalGraphCycleDetection\
    \ {\n    int n;\n    bool is_directed;\n    Graph<T> graph;\n    std::vector<bool>\
    \ reached, finished, in_cycle;\n    std::vector<T> history;\n\n    FunctionalGraphCycleDetection(Graph<T>\
    \ &graph, bool is_directed) : n((int)(graph.size())), is_directed(is_directed),\
    \ graph(graph), reached(n, false), finished(n, false), in_cycle(n, true) {\n \
    \       if (is_directed) for (int i = 0; i < n; i++) assert ((int)(graph[i].size())\
    \ == 1);\n        build();\n    }\n\n    /**\n     * @brief in_cycle\u3092\u69CB\
    \u7BC9\u3059\u308B\n     */\n    void build() {\n        std::queue<int> que;\n\
    \        std::vector<int> deg(n, 0);\n        int target = !is_directed;\n   \
    \     for (int i = 0; i < n; i++) for (auto c: graph[i]) deg[c]++;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (deg[i] == target) {\n           \
    \     que.push(i);\n                in_cycle[i] = false;\n            }\n    \
    \    }\n        while (!que.empty()) {\n            auto v = que.front(); que.pop();\n\
    \            for (auto c: graph[v]) {\n                if (!in_cycle[c]) continue;\n\
    \                deg[c]--;\n                if (deg[c] == target) {\n        \
    \            in_cycle[c] = false;\n                    que.push(c);\n        \
    \        }\n            }\n        }\n        return;\n    }\n\n    /**\n    \
    \ * @brief \u9802\u70B9pos\u304B\u3089\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u7BC9\
    \n     */\n    std::vector<T> reconstruct(int pos) {\n        std::vector<T> cycle;\n\
    \        int v = pos;\n        int parent = -1;\n        do {\n            cycle.push_back(v);\n\
    \            reached[v] = true;\n            for (auto c: graph[v]) {\n      \
    \          if (c == parent) continue;\n                if (!in_cycle[c]) continue;\n\
    \                v = c;\n                parent = v;\n                break;\n\
    \            }\n        } while (v != pos);\n        return cycle;\n    }\n\n\
    \    /**\n     * @brief \u5168\u3066\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u5217\
    \u6319\n     */\n    std::vector<std::vector<T>> detect_all() {\n        std::vector<std::vector<T>>\
    \ res;\n        for (int v = 0; v < (int)(graph.size()); v++) {\n            if\
    \ (!in_cycle[v] || reached[v]) continue;\n            std::vector<T> cycle = reconstruct(v);\n\
    \            if (!cycle.empty()) res.push_back(cycle);\n            else assert(false);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include \"graph_template.hpp\"\n\n/**\n\
    \ * @brief Functional Graph Cycle Detection (Functional Graph\u306E\u30B5\u30A4\
    \u30AF\u30EB\u691C\u51FA)\n */\ntemplate<class T> struct FunctionalGraphCycleDetection\
    \ {\n    int n;\n    bool is_directed;\n    Graph<T> graph;\n    std::vector<bool>\
    \ reached, finished, in_cycle;\n    std::vector<T> history;\n\n    FunctionalGraphCycleDetection(Graph<T>\
    \ &graph, bool is_directed) : n((int)(graph.size())), is_directed(is_directed),\
    \ graph(graph), reached(n, false), finished(n, false), in_cycle(n, true) {\n \
    \       if (is_directed) for (int i = 0; i < n; i++) assert ((int)(graph[i].size())\
    \ == 1);\n        build();\n    }\n\n    /**\n     * @brief in_cycle\u3092\u69CB\
    \u7BC9\u3059\u308B\n     */\n    void build() {\n        std::queue<int> que;\n\
    \        std::vector<int> deg(n, 0);\n        int target = !is_directed;\n   \
    \     for (int i = 0; i < n; i++) for (auto c: graph[i]) deg[c]++;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (deg[i] == target) {\n           \
    \     que.push(i);\n                in_cycle[i] = false;\n            }\n    \
    \    }\n        while (!que.empty()) {\n            auto v = que.front(); que.pop();\n\
    \            for (auto c: graph[v]) {\n                if (!in_cycle[c]) continue;\n\
    \                deg[c]--;\n                if (deg[c] == target) {\n        \
    \            in_cycle[c] = false;\n                    que.push(c);\n        \
    \        }\n            }\n        }\n        return;\n    }\n\n    /**\n    \
    \ * @brief \u9802\u70B9pos\u304B\u3089\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u7BC9\
    \n     */\n    std::vector<T> reconstruct(int pos) {\n        std::vector<T> cycle;\n\
    \        int v = pos;\n        int parent = -1;\n        do {\n            cycle.push_back(v);\n\
    \            reached[v] = true;\n            for (auto c: graph[v]) {\n      \
    \          if (c == parent) continue;\n                if (!in_cycle[c]) continue;\n\
    \                v = c;\n                parent = v;\n                break;\n\
    \            }\n        } while (v != pos);\n        return cycle;\n    }\n\n\
    \    /**\n     * @brief \u5168\u3066\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u5217\
    \u6319\n     */\n    std::vector<std::vector<T>> detect_all() {\n        std::vector<std::vector<T>>\
    \ res;\n        for (int v = 0; v < (int)(graph.size()); v++) {\n            if\
    \ (!in_cycle[v] || reached[v]) continue;\n            std::vector<T> cycle = reconstruct(v);\n\
    \            if (!cycle.empty()) res.push_back(cycle);\n            else assert(false);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/functional_graph_cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-09-06 05:08:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/functional_graph_cycle_detection.test.cpp
documentation_of: graph/functional_graph_cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/functional_graph_cycle_detection.hpp
- /library/graph/functional_graph_cycle_detection.hpp.html
title: "Functional Graph Cycle Detection (Functional Graph\u306E\u30B5\u30A4\u30AF\
  \u30EB\u691C\u51FA)"
---
