---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.hpp
    title: "Union-Find\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/data_structure/unionfind_1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n#include\
    \ <bits/stdc++.h>\n#line 2 \"data_structure/unionfind.hpp\"\n\n#line 4 \"data_structure/unionfind.hpp\"\
    \n\n/**\n * @brief Union-Find\u6728\n */\nstruct UnionFind {\n    private:\n \
    \   std::vector<int> parents;\n  \n    public:\n    UnionFind(int n) : parents(n,\
    \ -1) { }\n\n    /**\n     * @brief parents\u3092\u521D\u671F\u5316\u3059\u308B\
    \n     * @param n \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n     */\n    void\
    \ init(int n) { parents.assign(n, -1); }\n\n    /**\n     * @brief \u3042\u308B\
    \u9802\u70B9\u306E\u6839\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\
    \n     * @return \u305D\u306E\u9802\u70B9\u306E\u30EB\u30FC\u30C8\n     */\n \
    \   int root(int x) {\n        if (parents[x] < 0) return x;\n        else return\
    \ parents[x] = root(parents[x]);\n    }\n\n    /**\n     * @brief \u4E8C\u3064\
    \u306E\u9802\u70B9\u304C\u540C\u3058\u96C6\u56E3\u306B\u5C5E\u3057\u3066\u3044\
    \u308B\u304B\n     * @param x \u9802\u70B91\n     * @param y \u9802\u70B92\n \
    \    * @return \u9802\u70B91\u3068\u9802\u70B92\u304C\u540C\u3058\u96C6\u56E3\u306B\
    \u5C5E\u3057\u3066\u3044\u305F\u5834\u5408true\n     */\n    bool issame(int x,\
    \ int y) {\n        return root(x) == root(y);\n    }\n\n    /**\n     * @brief\
    \ \u4E8C\u3064\u306E\u9802\u70B9\u3092\u7D50\u5408\u3055\u305B\u308B\n     * @param\
    \ x \u9802\u70B91\n     * @param y \u9802\u70B92\n     */\n    void merge(int\
    \ x, int y) {\n        x = root(x);\n        y = root(y);\n        if (x == y)\
    \ return;\n        if (parents[x] > parents[y]) std::swap(x, y);\n        parents[x]\
    \ += parents[y]; // size\u3092\u8ABF\u6574\n        parents[y] = x; // \u5927\u304D\
    \u3044\u6728\u306E\u6839\u306B\u5C0F\u3055\u3044\u6728\u3092\u3064\u3051\u308B\
    , y\u306E\u89AA\u306Fx\n    }\n\n    /**\n     * @brief \u9802\u70B9\u306E\u5C5E\
    \u3057\u3066\u3044\u308B\u96C6\u56E3\u306E\u30B5\u30A4\u30BA\n     * @param x\
    \ \u9802\u70B9\n     * @return \u96C6\u56E3\u306E\u30B5\u30A4\u30BA\n     */\n\
    \    int size(int x) {\n        return -parents[root(x)];\n    }\n};\n#line 4\
    \ \"verify/data_structure/unionfind_1.test.cpp\"\nusing namespace std;\ntypedef\
    \ long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N; i++)\n\nint main()\
    \ {\n    ll N, Q; cin >> N >> Q;\n    UnionFind uf(N);\n    rep (i, Q) {\n   \
    \     ll type, a, b; cin >> type >> a >> b;\n        if (type == 0) {\n      \
    \      uf.merge(a, b);\n        } else if (type == 1) {\n            cout << uf.issame(a,\
    \ b) << endl;\n        } else {\n            assert(false);\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"data_structure/unionfind.hpp\"\nusing namespace\
    \ std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N;\
    \ i++)\n\nint main() {\n    ll N, Q; cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  rep (i, Q) {\n        ll type, a, b; cin >> type >> a >> b;\n        if (type\
    \ == 0) {\n            uf.merge(a, b);\n        } else if (type == 1) {\n    \
    \        cout << uf.issame(a, b) << endl;\n        } else {\n            assert(false);\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/unionfind.hpp
  isVerificationFile: true
  path: verify/data_structure/unionfind_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 15:53:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/unionfind_1.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/unionfind_1.test.cpp
- /verify/verify/data_structure/unionfind_1.test.cpp.html
title: verify/data_structure/unionfind_1.test.cpp
---
