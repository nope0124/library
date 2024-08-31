---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bipartite_graph.hpp
    title: graph/bipartite_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':warning:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u4E8C\u9802\u70B9\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u8ABF\
      \u3079\u308B"
  - icon: ':warning:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  - icon: ':warning:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
  - icon: ':warning:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra_1.test.cpp
    title: verify/graph/dijkstra_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\
      \u306E\u914D\u5217\u3092\u4F5C\u308B"
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\n#include <vector>\n\ntemplate<class\
    \ T> struct Graph {\n    int n;\n    std::vector<std::vector<T>> graph;\n\n  \
    \  Graph(int n) : n(n), graph(n, std::vector<T>()) {}\n    inline std::vector<T>&\
    \ operator[] (int i) { return graph[i]; }\n    size_t size() const { return graph.size();\
    \ }\n\n    std::vector<int> preorder, postorder;\n\n    /**\n     * @brief \u884C\
    \u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\u914D\u5217\
    \u3092\u4F5C\u308B\n     */\n    void calculateOrder() {\n        std::vector<bool>\
    \ reached(n, false);\n        auto dfs = [&](auto f, int v, int p) -> void {\n\
    \            if (reached[v]) return;\n            reached[v] = true;\n       \
    \     preorder.push_back(v);\n            for (auto c: graph[v]) {\n         \
    \       if (c == p) continue;\n                f(f, c, v);\n            }\n  \
    \          postorder.push_back(v);\n            return;\n        };\n\n      \
    \  for (int i = 0; i < n; i++) if (!reached[i]) dfs(dfs, i, -1);\n\n        assert((int)(preorder.size())\
    \ == n);\n        assert((int)(postorder.size()) == n);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate<class T> struct Graph {\n \
    \   int n;\n    std::vector<std::vector<T>> graph;\n\n    Graph(int n) : n(n),\
    \ graph(n, std::vector<T>()) {}\n    inline std::vector<T>& operator[] (int i)\
    \ { return graph[i]; }\n    size_t size() const { return graph.size(); }\n\n \
    \   std::vector<int> preorder, postorder;\n\n    /**\n     * @brief \u884C\u304D\
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
  - graph/strongly_connected_component.hpp
  - graph/topological_sort.hpp
  - graph/tree_diameter.hpp
  - graph/dijkstra.hpp
  - graph/lowest_common_ancestor.hpp
  - graph/bipartite_graph.hpp
  timestamp: '2024-08-30 23:10:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/dijkstra_1.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: "\u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\u914D\
  \u5217\u3092\u4F5C\u308B"
---
