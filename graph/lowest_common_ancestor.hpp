#include <vector>


std::vector<int> graph[100010];
const int MAX_DOUBLING = 40;
int parent[MAX_DOUBLING][100010];
int depth[100010];


void dfs(int v, int p, int d) {
    parent[0][v] = p; // 2^0遡るとpに到達
    depth[v] = d; // ルートからの深さ
    for(auto c: graph[v]) {
        if(c != p) dfs(c, v, d + 1);
    }
}

/**
 * @brief parentとdepthを初期化する
 * @param n グラフの頂点数
 */
void init(int n) {
    int root = 0;
    dfs(root, -1, 0); // parent[0]とdepthの初期化を行う

    // ダブリングで2^i遡った際の先祖の値を調べる
    for (int d = 0; d < MAX_DOUBLING - 1; d++) {
        for (int i = 0; i < n; i++) {
            if (parent[d][i] < 0) parent[d + 1][i] = -1;
            else parent[d + 1][i] = parent[d][parent[d][i]];
        }
    }
}

/**
 * @brief 二頂点の最小共通祖先を調べる
 * @param u 頂点1
 * @param v 頂点2
 * @return 最小共通祖先
 */
int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v); // u < v、vの方が深い状態にする
    for (int d = 0; d < MAX_DOUBLING; d++) {
        if((depth[v] - depth[u]) >> d & 1) {
            v = parent[d][v]; // 深さを合わせる
        }
    }
    // この時点で一致したらそれが最小共通祖先
    if (u == v) return u;
    for (int d = MAX_DOUBLING - 1; d >= 0; d--){
        if (parent[d][u] != parent[d][v]) {
            u = parent[d][u];
            v = parent[d][v];
        }
    }
    return parent[0][u];
}