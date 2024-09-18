#define PROBLEM "https://atcoder.jp/contests/abc327/tasks/abc327_d"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/bipartite_graph.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(M), B(M);
    Graph<ll> graph(N);
    rep (i, M) cin >> A[i], A[i]--;
    rep (i, M) cin >> B[i], B[i]--;
    rep (i, M) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }

    BipartiteGraph<ll> bg(graph);
    if (bg.isBipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
