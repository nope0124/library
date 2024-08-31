---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
    links: []
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.hpp\"\n\n#include <vector>\n\
    #line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\n\
    \n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\
    template<class T> struct Edge {\n    int to;\n    T cost;\n\n    Edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n};\n\ntemplate<class T> struct Graph {\n  \
    \  int n;\n    std::vector<std::vector<T>> graph;\n\n    Graph(int n) : n(n),\
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
    \ == n);\n        assert((int)(postorder.size()) == n);\n    }\n};\n#line 5 \"\
    graph/lowest_common_ancestor.hpp\"\n\n/**\n * @brief Lowest Common Ancestor (\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n */\ntemplate<class T> struct LowestCommonAncestor\
    \ {\n    int n;\n    const int MAX_DOUBLING = 40;\n    std::vector<int> depth;\n\
    \    std::vector<std::vector<int>> parents;\n    \n    LowestCommonAncestor(Graph<T>\
    \ &graph, const int root = 0) : n((int)(graph.size())), depth(n, 0), parents(MAX_DOUBLING,\
    \ std::vector<int>(n)) {\n        auto dfs = [&](auto f, int v, int p, int d)\
    \ -> void {\n            parents[0][v] = p; // 2^0\u9061\u308B\u3068p\u306B\u5230\
    \u9054\n            depth[v] = d; // \u30EB\u30FC\u30C8\u304B\u3089\u306E\u6DF1\
    \u3055\n            for (auto c: graph[v]) {\n                if (c != p) f(f,\
    \ c, v, d + 1);\n            }\n        };\n\n        dfs(dfs, root, -1, 0); //\
    \ parents[0]\u3068depth\u306E\u521D\u671F\u5316\u3092\u884C\u3046\n\n        //\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u30672^i\u9061\u3063\u305F\u969B\u306E\u5148\u7956\
    \u306E\u5024\u3092\u8ABF\u3079\u308B\n        for (int d = 0; d < MAX_DOUBLING\
    \ - 1; d++) {\n            for (int i = 0; i < n; i++) {\n                if (parents[d][i]\
    \ < 0) parents[d + 1][i] = -1;\n                else parents[d + 1][i] = parents[d][parents[d][i]];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u9802\u70B9\u306E\
    \u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u8ABF\u3079\u308B\n     * @param u\
    \ \u9802\u70B91\n     * @param v \u9802\u70B92\n     * @return \u6700\u5C0F\u5171\
    \u901A\u7956\u5148\n     */\n    int lca(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) std::swap(u, v); // u < v\u3001v\u306E\u65B9\u304C\u6DF1\u3044\u72B6\
    \u614B\u306B\u3059\u308B\n        for (int d = 0; d < MAX_DOUBLING; d++) {\n \
    \           if((long long int)(depth[v] - depth[u]) >> d & 1) {\n            \
    \    v = parents[d][v]; // \u6DF1\u3055\u3092\u5408\u308F\u305B\u308B\n      \
    \      }\n        }\n        // \u3053\u306E\u6642\u70B9\u3067\u4E00\u81F4\u3057\
    \u305F\u3089\u305D\u308C\u304C\u6700\u5C0F\u5171\u901A\u7956\u5148\n        if\
    \ (u == v) return u;\n        for (int d = MAX_DOUBLING - 1; d >= 0; d--){\n \
    \           if (parents[d][u] != parents[d][v]) {\n                u = parents[d][u];\n\
    \                v = parents[d][v];\n            }\n        }\n        return\
    \ parents[0][u];\n    }\n\n    /**\n     * @brief \u4E8C\u9802\u70B9\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3092\u8ABF\u3079\u308B\n     * @param u \u9802\u70B91\n  \
    \   * @param v \u9802\u70B92\n     * @return \u6700\u77ED\u8DDD\u96E2\n     */\n\
    \    int dist(int u, int v) {\n        return depth[u] + depth[v] - 2 * depth[lca(u,\
    \ v)];\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include \"graph_template.hpp\"\n\n/**\n\
    \ * @brief Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)\n */\n\
    template<class T> struct LowestCommonAncestor {\n    int n;\n    const int MAX_DOUBLING\
    \ = 40;\n    std::vector<int> depth;\n    std::vector<std::vector<int>> parents;\n\
    \    \n    LowestCommonAncestor(Graph<T> &graph, const int root = 0) : n((int)(graph.size())),\
    \ depth(n, 0), parents(MAX_DOUBLING, std::vector<int>(n)) {\n        auto dfs\
    \ = [&](auto f, int v, int p, int d) -> void {\n            parents[0][v] = p;\
    \ // 2^0\u9061\u308B\u3068p\u306B\u5230\u9054\n            depth[v] = d; // \u30EB\
    \u30FC\u30C8\u304B\u3089\u306E\u6DF1\u3055\n            for (auto c: graph[v])\
    \ {\n                if (c != p) f(f, c, v, d + 1);\n            }\n        };\n\
    \n        dfs(dfs, root, -1, 0); // parents[0]\u3068depth\u306E\u521D\u671F\u5316\
    \u3092\u884C\u3046\n\n        // \u30C0\u30D6\u30EA\u30F3\u30B0\u30672^i\u9061\
    \u3063\u305F\u969B\u306E\u5148\u7956\u306E\u5024\u3092\u8ABF\u3079\u308B\n   \
    \     for (int d = 0; d < MAX_DOUBLING - 1; d++) {\n            for (int i = 0;\
    \ i < n; i++) {\n                if (parents[d][i] < 0) parents[d + 1][i] = -1;\n\
    \                else parents[d + 1][i] = parents[d][parents[d][i]];\n       \
    \     }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u9802\u70B9\u306E\u6700\
    \u5C0F\u5171\u901A\u7956\u5148\u3092\u8ABF\u3079\u308B\n     * @param u \u9802\
    \u70B91\n     * @param v \u9802\u70B92\n     * @return \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n     */\n    int lca(int u, int v) {\n        if (depth[u] > depth[v])\
    \ std::swap(u, v); // u < v\u3001v\u306E\u65B9\u304C\u6DF1\u3044\u72B6\u614B\u306B\
    \u3059\u308B\n        for (int d = 0; d < MAX_DOUBLING; d++) {\n            if((long\
    \ long int)(depth[v] - depth[u]) >> d & 1) {\n                v = parents[d][v];\
    \ // \u6DF1\u3055\u3092\u5408\u308F\u305B\u308B\n            }\n        }\n  \
    \      // \u3053\u306E\u6642\u70B9\u3067\u4E00\u81F4\u3057\u305F\u3089\u305D\u308C\
    \u304C\u6700\u5C0F\u5171\u901A\u7956\u5148\n        if (u == v) return u;\n  \
    \      for (int d = MAX_DOUBLING - 1; d >= 0; d--){\n            if (parents[d][u]\
    \ != parents[d][v]) {\n                u = parents[d][u];\n                v =\
    \ parents[d][v];\n            }\n        }\n        return parents[0][u];\n  \
    \  }\n\n    /**\n     * @brief \u4E8C\u9802\u70B9\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u8ABF\u3079\u308B\n     * @param u \u9802\u70B91\n     * @param v \u9802\
    \u70B92\n     * @return \u6700\u77ED\u8DDD\u96E2\n     */\n    int dist(int u,\
    \ int v) {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\
    };"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-09-01 02:25:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/graph/lowest_common_ancestor.hpp
- /library/graph/lowest_common_ancestor.hpp.html
title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
