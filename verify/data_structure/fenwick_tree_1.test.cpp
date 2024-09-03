#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
#include "data_structure/fenwick_tree.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, Q; cin >> N >> Q;
    FenwickTree<ll> bit(N);
    rep (i, Q) {
        ll type; cin >> type;
        if (type == 0) {
            ll idx, x; cin >> idx >> x; idx--;
            bit.add(idx, x);
        } else if (type == 1) {
            ll left, right; cin >> left >> right; left--;
            cout << bit.getSum(left, right) << endl;
        } else {
            assert(false);
        }
    }

    return 0;
}