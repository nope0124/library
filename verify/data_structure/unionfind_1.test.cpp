#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include <bits/stdc++.h>
#include "data_structure/unionfind.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, Q; cin >> N >> Q;
    UnionFind uf(N);
    rep (i, Q) {
        ll type, a, b; cin >> type >> a >> b;
        if (type == 0) {
            uf.merge(a, b);
        } else if (type == 1) {
            cout << uf.issame(a, b) << endl;
        } else {
            assert(false);
        }
    }
    return 0;
}