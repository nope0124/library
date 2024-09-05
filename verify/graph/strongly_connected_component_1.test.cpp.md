---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"verify/graph/strongly_connected_component_1.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <bits/stdc++.h>\n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"\
    graph/graph_template.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n */\ntemplate<class T> struct Edge {\n    int from;\n    int\
    \ to;\n    T cost;\n\n    Edge(int from = -1, int to = -1, T cost = -1) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate<class T> struct Graph {\n    int n;\n\
    \    std::vector<std::vector<T>> graph;\n\n    Graph(int n) : n(n), graph(n, std::vector<T>())\
    \ {}\n    inline std::vector<T>& operator[] (int i) { return graph[i]; }\n   \
    \ size_t size() const { return graph.size(); }\n\n    std::vector<int> preorder,\
    \ postorder;\n\n    /**\n     * @brief \u884C\u304D\u304C\u3051\u9806\u3001\u5E30\
    \u308A\u304C\u3051\u9806\u306E\u914D\u5217\u3092\u4F5C\u308B\n     */\n    void\
    \ calculateOrder() {\n        std::vector<bool> reached(n, false);\n        auto\
    \ dfs = [&](auto f, int v, int p) -> void {\n            if (reached[v]) return;\n\
    \            reached[v] = true;\n            preorder.push_back(v);\n        \
    \    for (auto c: graph[v]) {\n                if (c == p) continue;\n       \
    \         f(f, c, v);\n            }\n            postorder.push_back(v);\n  \
    \          return;\n        };\n\n        for (int i = 0; i < n; i++) if (!reached[i])\
    \ dfs(dfs, i, -1);\n\n        assert((int)(preorder.size()) == n);\n        assert((int)(postorder.size())\
    \ == n);\n    }\n};\n#line 2 \"graph/strongly_connected_component.hpp\"\n\n#line\
    \ 6 \"graph/strongly_connected_component.hpp\"\n\n/**\n * @brief Strongly Connected\
    \ Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n */\ntemplate<class\
    \ T> struct StronglyConnectedComponent {\n    int n, sz;\n    std::vector<int>\
    \ idxs;\n    std::vector<std::vector<int>> groups;\n\n    StronglyConnectedComponent(Graph<T>\
    \ &graph, Graph<T> &graphRev) : n((int)(graph.size())), idxs(n, -1), groups(n)\
    \ {\n        graph.calculateOrder();\n        std::vector<int> postorder = graph.postorder;\n\
    \        reverse(postorder.begin(), postorder.end());\n\n        int idx = 0;\n\
    \        auto dfs = [&](auto f, int v, int p) -> void {\n            if (idxs[v]\
    \ != -1) return;\n            idxs[v] = idx;\n            groups[idx].push_back(v);\n\
    \            for (auto c: graphRev[v]) {\n                if (c == p) continue;\n\
    \                f(f, c, v);\n            }\n            return;\n        };\n\
    \n        for (int i = 0; i < n; i++) {\n            if (idxs[postorder[i]] !=\
    \ -1) continue;\n            dfs(dfs, postorder[i], -1);\n            idx++;\n\
    \        }\n\n        sz = idx;\n\n        return;\n    }\n};\n#line 5 \"verify/graph/strongly_connected_component_1.test.cpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\n\nint main() {\n    ll N, M; cin >> N >> M;\n    Graph<ll>\
    \ graph(N), graphRev(N);\n    rep (i, M) {\n        ll a, b; cin >> a >> b;\n\
    \        graph[a].push_back(b);\n        graphRev[b].push_back(a);\n    }\n\n\
    \    StronglyConnectedComponent<ll> scc(graph, graphRev);\n    ll Q; cin >> Q;\n\
    \    rep (i, Q) {\n        ll a, b; cin >> a >> b;\n        if (scc.idxs[a] ==\
    \ scc.idxs[b]) cout << 1 << endl;\n        else cout << 0 << endl;\n    }\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <bits/stdc++.h>\n#include \"graph/graph_template.hpp\"\n#include \"\
    graph/strongly_connected_component.hpp\"\nusing namespace std;\ntypedef long long\
    \ int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N; i++)\n\nint main() {\n \
    \   ll N, M; cin >> N >> M;\n    Graph<ll> graph(N), graphRev(N);\n    rep (i,\
    \ M) {\n        ll a, b; cin >> a >> b;\n        graph[a].push_back(b);\n    \
    \    graphRev[b].push_back(a);\n    }\n\n    StronglyConnectedComponent<ll> scc(graph,\
    \ graphRev);\n    ll Q; cin >> Q;\n    rep (i, Q) {\n        ll a, b; cin >> a\
    \ >> b;\n        if (scc.idxs[a] == scc.idxs[b]) cout << 1 << endl;\n        else\
    \ cout << 0 << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph_template.hpp
  - graph/strongly_connected_component.hpp
  isVerificationFile: true
  path: verify/graph/strongly_connected_component_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 13:55:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/strongly_connected_component_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/strongly_connected_component_1.test.cpp
- /verify/verify/graph/strongly_connected_component_1.test.cpp.html
title: verify/graph/strongly_connected_component_1.test.cpp
---
