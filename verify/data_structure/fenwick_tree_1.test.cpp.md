---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/data_structure/fenwick_tree_1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\n#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#line\
    \ 4 \"data_structure/fenwick_tree.hpp\"\n\n/**\n * @brief Fenwick Tree (Binary\
    \ Indexed Tree)\n */\ntemplate<class T> struct FenwickTree {\n    private:\n \
    \   int n;\n    std::vector<int> bit;\n\n    public:\n    FenwickTree(int n) :\
    \ n(n), bit(n + 1, T(0)) {}\n    FenwickTree(std::vector<T>& V) : n((int)(V.size())),\
    \ bit(n + 1, T(0)) {\n        for (int i = 0; i < n; i++) add(i, V[i]);\n    }\n\
    \n    // 0-indexed\u3067\u5024\u3092\u8FFD\u52A0\n    // V[idx] += x\n    void\
    \ add(int idx, T x) {\n        assert(0 <= idx && idx < n);\n        idx++; //\
    \ 1-indexed\u306B\u3059\u308B\n        assert(1 <= idx && idx <= n);\n       \
    \ while (idx <= n) {\n            bit[idx] += x;\n            idx += (idx & -idx);\n\
    \        }\n    }\n\n    // V[0, idx)\u306E\u548C\u3092\u53D6\u5F97\n    T getSum(int\
    \ idx) {\n        assert(0 <= idx && idx <= n);\n        T res = 0;\n        while\
    \ (idx > 0) {\n            res += bit[idx];\n            idx -= (idx & -idx);\n\
    \        }\n        return res;\n    }\n\n    // V[left, right) = V[0, right)\
    \ - V[0, left)\n    T getSum(int left, int right) {\n        assert(0 <= left\
    \ && left <= right && right <= n);\n        return getSum(right) - getSum(left);\n\
    \    }\n\n    // V[idx] = V[idx, idx + 1) = V[0, idx + 1) - V[0, idx)\n    T get(int\
    \ idx) {\n        assert(0 <= idx && idx < n);\n        return getSum(idx + 1)\
    \ - getSum(idx);\n    }\n\n    // V[idx] = x\n    void update(int idx, T x) {\n\
    \        assert(0 <= idx && idx < n);\n        add(idx, x - get(idx));\n    }\n\
    \n    std::vector<T> getVector() {\n        std::vector<T> V(n);\n        for\
    \ (int i = 0; i < n; i++) V[i] = get(i);\n        return V;\n    }\n};\n#line\
    \ 4 \"verify/data_structure/fenwick_tree_1.test.cpp\"\nusing namespace std;\n\
    typedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N; i++)\n\n\
    int main() {\n    ll N, Q; cin >> N >> Q;\n    FenwickTree<ll> bit(N);\n    rep\
    \ (i, Q) {\n        ll type; cin >> type;\n        if (type == 0) {\n        \
    \    ll idx, x; cin >> idx >> x; idx--;\n            bit.add(idx, x);\n      \
    \  } else if (type == 1) {\n            ll left, right; cin >> left >> right;\
    \ left--;\n            cout << bit.getSum(left, right) << endl;\n        } else\
    \ {\n            assert(false);\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\n#include \"data_structure/fenwick_tree.hpp\"\nusing\
    \ namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i\
    \ < (ll)N; i++)\n\nint main() {\n    ll N, Q; cin >> N >> Q;\n    FenwickTree<ll>\
    \ bit(N);\n    rep (i, Q) {\n        ll type; cin >> type;\n        if (type ==\
    \ 0) {\n            ll idx, x; cin >> idx >> x; idx--;\n            bit.add(idx,\
    \ x);\n        } else if (type == 1) {\n            ll left, right; cin >> left\
    \ >> right; left--;\n            cout << bit.getSum(left, right) << endl;\n  \
    \      } else {\n            assert(false);\n        }\n    }\n\n    return 0;\n\
    }"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/data_structure/fenwick_tree_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 05:50:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/fenwick_tree_1.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/fenwick_tree_1.test.cpp
- /verify/verify/data_structure/fenwick_tree_1.test.cpp.html
title: verify/data_structure/fenwick_tree_1.test.cpp
---
