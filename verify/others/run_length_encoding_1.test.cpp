#define PROBLEM "https://atcoder.jp/contests/abc329/tasks/abc329_c"
#include <bits/stdc++.h>
#include "others/run_length_encoding.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    string S; cin >> S;
    auto res = run_length_encoding(S);
    vector<ll> cnt(26, 0);
    rep (i, res.size()) cnt[res[i].first - 'a'] = max(cnt[res[i].first - 'a'], (ll)res[i].second);
    ll ans = 0;
    rep (i, 26) ans += cnt[i];
    cout << ans << endl;

    return 0;
}