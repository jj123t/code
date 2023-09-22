/*************************************************************************
	> File Name: p4281.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 13 Apr 2023 08:11:14 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
vector<int> e[N];
int par[N][21];
vector<int> dep(N, 0);
void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= 20; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i > -1; i--) {
        if (dep[par[u][i]] >= dep[v]) {
            u = par[u][i];
        }
    }
    if (v == u) return v;
    for (int i = 20; i > -1; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        int a = lca(u, v);
        int b = lca(u, w);
        int c = lca(v, w);
        int tp;
        if (a == b) tp = c;
        if (b == c) tp = a;
        if (a == c) tp = b;
        ll mx = (ll)(dep[u] + dep[v] + dep[w] - dep[a] - dep[b] - dep[c]);
        cout << tp << " " << mx << "\n";
    }
    return 0;

}
