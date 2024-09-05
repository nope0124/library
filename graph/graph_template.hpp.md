---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/bipartite_graph.hpp
    title: "Bipartite Graph (\u4E8C\u90E8\u30B0\u30E9\u30D5)"
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  - icon: ':question:'
    path: graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/bipartite_graph_1.test.cpp
    title: verify/graph/bipartite_graph_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra_1.test.cpp
    title: verify/graph/dijkstra_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_1.test.cpp
    title: verify/graph/lowest_common_ancestor_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/strongly_connected_component_1.test.cpp
    title: verify/graph/strongly_connected_component_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/topological_sort_1.test.cpp
    title: verify/graph/topological_sort_1.test.cpp
  - icon: ':x:'
    path: verify/graph/topological_sort_2.test.cpp
    title: verify/graph/topological_sort_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter_1.test.cpp
    title: verify/graph/tree_diameter_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\n#include <vector>\n\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\ntemplate<class\
    \ T> struct Edge {\n    int from;\n    int to;\n    T cost;\n\n    Edge(int from\
    \ = -1, int to = -1, T cost = -1) : from(from), to(to), cost(cost) {}\n};\n\n\
    template<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
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
    \ == n);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\ntemplate<class T> struct Edge {\n    int\
    \ from;\n    int to;\n    T cost;\n\n    Edge(int from = -1, int to = -1, T cost\
    \ = -1) : from(from), to(to), cost(cost) {}\n};\n\ntemplate<class T> struct Graph\
    \ {\n    int n;\n    std::vector<std::vector<T>> graph;\n\n    Graph(int n) :\
    \ n(n), graph(n, std::vector<T>()) {}\n    inline std::vector<T>& operator[] (int\
    \ i) { return graph[i]; }\n    size_t size() const { return graph.size(); }\n\n\
    \    std::vector<int> preorder, postorder;\n\n    /**\n     * @brief \u884C\u304D\
    \u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\u914D\u5217\u3092\
    \u4F5C\u308B\n     */\n    void calculateOrder() {\n        std::vector<bool>\
    \ reached(n, false);\n        auto dfs = [&](auto f, int v, int p) -> void {\n\
    \            if (reached[v]) return;\n            reached[v] = true;\n       \
    \     preorder.push_back(v);\n            for (auto c: graph[v]) {\n         \
    \       if (c == p) continue;\n                f(f, c, v);\n            }\n  \
    \          postorder.push_back(v);\n            return;\n        };\n\n      \
    \  for (int i = 0; i < n; i++) if (!reached[i]) dfs(dfs, i, -1);\n\n        assert((int)(preorder.size())\
    \ == n);\n        assert((int)(postorder.size()) == n);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  - graph/strongly_connected_component.hpp
  - graph/tree_diameter.hpp
  - graph/topological_sort.hpp
  - graph/bipartite_graph.hpp
  - graph/dijkstra.hpp
  timestamp: '2024-09-05 13:55:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/graph/bipartite_graph_1.test.cpp
  - verify/graph/tree_diameter_1.test.cpp
  - verify/graph/dijkstra_1.test.cpp
  - verify/graph/topological_sort_2.test.cpp
  - verify/graph/strongly_connected_component_1.test.cpp
  - verify/graph/topological_sort_1.test.cpp
  - verify/graph/lowest_common_ancestor_1.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
