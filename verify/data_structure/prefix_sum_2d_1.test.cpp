#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include <bits/stdc++.h>
#include "data_structure/prefix_sum_2d.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    vector<vector<ll>> V(1010, vector<ll>(1010, 0));
    rep (i, N) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        V[y1][x1]++;
        V[y2][x2]++;
        V[y1][x2]--;
        V[y2][x1]--;
    }
    PrefixSum2D<ll> ps(V);
    ll ans = 0;
    rep (i, ps.h) {
        rep (j, ps.w) {
            ans = max(ans, ps.get(j, i));
        }
    }
    cout << ans << endl;

    return 0;
}