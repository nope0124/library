#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/topological_sort.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()

int main() {
    ll N, M; cin >> N >> M;
    Graph<ll> graph(N);
    rep (i, M) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    
    auto ans = topological_sort(graph);
    rep (i, N) cout << ans[i] << endl;

    return 0;
}
