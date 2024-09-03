#include <bits/stdc++.h>
#include "is_parenthesis.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()

int main() {
    ll N; cin >> N;
    vector<string> ans;
    rep (bit, (1LL<<N)) {
        string parenthesis = "";
        rep (i, N) {
            if (bit >> i & 1) parenthesis += '(';
            else parenthesis += ')';
        }
        if (!is_parenthesis(parenthesis)) continue;
        ans.push_back(parenthesis);
    }
    sort(ALL(ans));
    rep (i, ans.size()) cout << ans[i] << "\n";

    return 0;
}