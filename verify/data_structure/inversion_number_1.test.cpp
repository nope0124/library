#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include <bits/stdc++.h>
#include "data_structure/inversion_number.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    vector<ll> V(N);
    rep (i, N) cin >> V[i];
    cout << inversion_number(V) << endl;
    return 0;
}