---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/inversion_number_1.test.cpp
    title: verify/data_structure/inversion_number_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Inversion Number (\u8EE2\u5012\u6570)"
    links: []
  bundledCode: "#line 2 \"data_structure/inversion_number.hpp\"\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\n#include <vector>\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n */\n\
    template<class T> struct FenwickTree {\n    private:\n    int n;\n    std::vector<int>\
    \ bit;\n\n    public:\n    FenwickTree(int n) : n(n), bit(n + 1, T(0)) {}\n  \
    \  FenwickTree(std::vector<T>& V) : n((int)(V.size())), bit(n + 1, T(0)) {\n \
    \       for (int i = 0; i < n; i++) add(i, V[i]);\n    }\n\n    // 0-indexed\u3067\
    \u5024\u3092\u8FFD\u52A0\n    // V[idx] += x\n    void add(int idx, T x) {\n \
    \       assert(0 <= idx && idx < n);\n        idx++; // 1-indexed\u306B\u3059\u308B\
    \n        assert(1 <= idx && idx <= n);\n        while (idx <= n) {\n        \
    \    bit[idx] += x;\n            idx += (idx & -idx);\n        }\n    }\n\n  \
    \  // V[0, idx)\u306E\u548C\u3092\u53D6\u5F97\n    T getSum(int idx) {\n     \
    \   assert(0 <= idx && idx <= n);\n        T res = 0;\n        while (idx > 0)\
    \ {\n            res += bit[idx];\n            idx -= (idx & -idx);\n        }\n\
    \        return res;\n    }\n\n    // V[left, right) = V[0, right) - V[0, left)\n\
    \    T getSum(int left, int right) {\n        assert(0 <= left && left <= right\
    \ && right <= n);\n        return getSum(right) - getSum(left);\n    }\n\n   \
    \ // V[idx] = V[idx, idx + 1) = V[0, idx + 1) - V[0, idx)\n    T get(int idx)\
    \ {\n        assert(0 <= idx && idx < n);\n        return getSum(idx + 1) - getSum(idx);\n\
    \    }\n\n    // V[idx] = x\n    void update(int idx, T x) {\n        assert(0\
    \ <= idx && idx < n);\n        add(idx, x - get(idx));\n    }\n\n    std::vector<T>\
    \ getVector() {\n        std::vector<T> V(n);\n        for (int i = 0; i < n;\
    \ i++) V[i] = get(i);\n        return V;\n    }\n};\n#line 4 \"data_structure/inversion_number.hpp\"\
    \n\n/**\n * @brief Inversion Number (\u8EE2\u5012\u6570)\n */\ntemplate<class\
    \ T> long long inversion_number(std::vector<T>& V) {\n    std::vector<T> W = V;\n\
    \    sort(W.begin(), W.end());\n    W.erase(unique(W.begin(), W.end()), W.end());\n\
    \    int n = (int)(W.size());\n    FenwickTree<int> bit(n);\n    long long res\
    \ = 0;\n    for (auto v: V) {\n        int idx = lower_bound(W.begin(), W.end(),\
    \ v) - W.begin();\n        res += bit.getSum(idx + 1, n);\n        bit.add(idx,\
    \ 1);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"data_structure/fenwick_tree.hpp\"\n\n/**\n * @brief\
    \ Inversion Number (\u8EE2\u5012\u6570)\n */\ntemplate<class T> long long inversion_number(std::vector<T>&\
    \ V) {\n    std::vector<T> W = V;\n    sort(W.begin(), W.end());\n    W.erase(unique(W.begin(),\
    \ W.end()), W.end());\n    int n = (int)(W.size());\n    FenwickTree<int> bit(n);\n\
    \    long long res = 0;\n    for (auto v: V) {\n        int idx = lower_bound(W.begin(),\
    \ W.end(), v) - W.begin();\n        res += bit.getSum(idx + 1, n);\n        bit.add(idx,\
    \ 1);\n    }\n    return res;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: data_structure/inversion_number.hpp
  requiredBy: []
  timestamp: '2024-09-04 06:39:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/inversion_number_1.test.cpp
documentation_of: data_structure/inversion_number.hpp
layout: document
redirect_from:
- /library/data_structure/inversion_number.hpp
- /library/data_structure/inversion_number.hpp.html
title: "Inversion Number (\u8EE2\u5012\u6570)"
---
