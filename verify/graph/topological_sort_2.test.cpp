#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_d"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/topological_sort.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, M; cin >> N >> M;
    Graph<ll> graph(N);
    rep (i, M) {
        ll a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
    }

    auto V = topological_sort(graph);
    if ((int)(V.size()) != N) {
        cout << -1 << endl;
        return 0;
    }
    rep (i, N) {
        if (i == 0) cout << V[i] + 1;
        else cout << ' ' << V[i] + 1;
    }
    cout << endl;
    return 0;
}
