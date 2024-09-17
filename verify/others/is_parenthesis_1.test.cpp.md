---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: others/is_parenthesis.hpp
    title: "\u62EC\u5F27\u5217\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/typical90/tasks/typical90_b
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_b
  bundledCode: "#line 1 \"verify/others/is_parenthesis_1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/typical90/tasks/typical90_b\"\n#include <bits/stdc++.h>\n\
    #line 2 \"others/is_parenthesis.hpp\"\n\n#line 4 \"others/is_parenthesis.hpp\"\
    \n\n/**\n * @brief \u62EC\u5F27\u5217\u5224\u5B9A\n */\nbool is_parenthesis(std::string&\
    \ parenthesis) {\n    int depth = 0;\n    for (int i = 0; i < (int)(parenthesis.size());\
    \ i++) {\n        if (parenthesis[i] == '(') depth++;\n        if (parenthesis[i]\
    \ == ')') depth--;\n        if (depth < 0) return false;\n    }\n    return (depth\
    \ == 0);\n}\n#line 4 \"verify/others/is_parenthesis_1.test.cpp\"\nusing namespace\
    \ std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N;\
    \ i++)\n#define ALL(V)  (V).begin(), (V).end()\n\nint main() {\n    ll N; cin\
    \ >> N;\n    vector<string> ans;\n    rep (bit, (1LL<<N)) {\n        string parenthesis\
    \ = \"\";\n        rep (i, N) {\n            if (bit >> i & 1) parenthesis +=\
    \ '(';\n            else parenthesis += ')';\n        }\n        if (!is_parenthesis(parenthesis))\
    \ continue;\n        ans.push_back(parenthesis);\n    }\n    sort(ALL(ans));\n\
    \    rep (i, ans.size()) cout << ans[i] << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_b\"\
    \n#include <bits/stdc++.h>\n#include \"others/is_parenthesis.hpp\"\nusing namespace\
    \ std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N;\
    \ i++)\n#define ALL(V)  (V).begin(), (V).end()\n\nint main() {\n    ll N; cin\
    \ >> N;\n    vector<string> ans;\n    rep (bit, (1LL<<N)) {\n        string parenthesis\
    \ = \"\";\n        rep (i, N) {\n            if (bit >> i & 1) parenthesis +=\
    \ '(';\n            else parenthesis += ')';\n        }\n        if (!is_parenthesis(parenthesis))\
    \ continue;\n        ans.push_back(parenthesis);\n    }\n    sort(ALL(ans));\n\
    \    rep (i, ans.size()) cout << ans[i] << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - others/is_parenthesis.hpp
  isVerificationFile: true
  path: verify/others/is_parenthesis_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-18 01:14:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/others/is_parenthesis_1.test.cpp
layout: document
redirect_from:
- /verify/verify/others/is_parenthesis_1.test.cpp
- /verify/verify/others/is_parenthesis_1.test.cpp.html
title: verify/others/is_parenthesis_1.test.cpp
---
