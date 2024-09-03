---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: others/run_length_encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (Run Length Encoding)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc329/tasks/abc329_c
    links:
    - https://atcoder.jp/contests/abc329/tasks/abc329_c
  bundledCode: "#line 1 \"verify/others/run_length_encoding_1.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc329/tasks/abc329_c\"\n#include <bits/stdc++.h>\n\
    #line 2 \"others/run_length_encoding.hpp\"\n\n#line 6 \"others/run_length_encoding.hpp\"\
    \n\n/**\n * @brief \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (Run Length\
    \ Encoding)\n */\ntemplate<class T> std::vector<std::pair<T, int>> run_length_encoding(std::vector<T>&\
    \ V) {\n    assert((int)(V.size()) > 0);\n    std::vector<std::pair<T, int>> res\
    \ = {std::pair<T, int>(V.front(), 0)};\n    for (auto c: V) {\n        if (c !=\
    \ res.back().first) {\n            res.push_back(std::pair<T, int>(c, 0));\n \
    \       }\n        res.back().second++;\n    }\n    return res;\n}\n\nstd::vector<std::pair<char,\
    \ int>> run_length_encoding(std::string& S) {\n    int n = (int)(S.size());\n\
    \    std::vector<char> V(n);\n    for (int i = 0; i < n; i++) V[i] = S[i];\n \
    \   return run_length_encoding(V);\n}\n#line 4 \"verify/others/run_length_encoding_1.test.cpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\n\nint main() {\n    ll N; cin >> N;\n    string S; cin\
    \ >> S;\n    auto res = run_length_encoding(S);\n    vector<ll> cnt(26, 0);\n\
    \    rep (i, res.size()) cnt[res[i].first - 'a'] = max(cnt[res[i].first - 'a'],\
    \ (ll)res[i].second);\n    ll ans = 0;\n    rep (i, 26) ans += cnt[i];\n    cout\
    \ << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc329/tasks/abc329_c\"\n#include\
    \ <bits/stdc++.h>\n#include \"others/run_length_encoding.hpp\"\nusing namespace\
    \ std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N;\
    \ i++)\n\nint main() {\n    ll N; cin >> N;\n    string S; cin >> S;\n    auto\
    \ res = run_length_encoding(S);\n    vector<ll> cnt(26, 0);\n    rep (i, res.size())\
    \ cnt[res[i].first - 'a'] = max(cnt[res[i].first - 'a'], (ll)res[i].second);\n\
    \    ll ans = 0;\n    rep (i, 26) ans += cnt[i];\n    cout << ans << endl;\n\n\
    \    return 0;\n}"
  dependsOn:
  - others/run_length_encoding.hpp
  isVerificationFile: true
  path: verify/others/run_length_encoding_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 05:39:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/others/run_length_encoding_1.test.cpp
layout: document
redirect_from:
- /verify/verify/others/run_length_encoding_1.test.cpp
- /verify/verify/others/run_length_encoding_1.test.cpp.html
title: verify/others/run_length_encoding_1.test.cpp
---
