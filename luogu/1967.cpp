/*************************************************************************
	> File Name: 1967.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 12:41:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
const int INF = 1e17;
vector<int> par(N), dep(N);
vector<array<int, 3>> edge;
vector<vector<int>> wig(N, vector<int>(27, INF));
vector<vector<int>> f(N, vector<int>(27, 0));
vector<pair<int, int>> e[N];
bool vis[N];
void init(int n) { for (int i = 1; i <= n; i++) par[i] = i; }
int Find(int x) { if (par[x] == x) return x; return par[x] = Find(par[x]); }
void Unite(int x, int y) { par[Find(x)] = Find(y); }
bool Same(int x, int y) { return Find(x) == Find(y); }
void kustral() {
    sort(edge.rbegin(), edge.rend());
    for (auto [w, u, v] : edge) {
        if (Same(u, v)) continue;
        Unite(u, v);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
}
void dfs(int u, int p) {
    vis[u] = true;
    dep[u] = dep[p] + 1;
    f[u][0] = p;
    for (int i = 1; i <= 26; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
        wig[u][i] = min(wig[u][i - 1], wig[f[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : e[u]) {
        if (v == p) continue;
        wig[v][0] = w;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int ans = INF;
    for (int i = 26; i >= 0; i--) {
        if (dep[f[u][i]] >= dep[v]) {
            ans = min(ans, wig[u][i]);
            u = f[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = 26; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            ans = min(ans, min(wig[u][i], wig[v][i]));
            u = f[u][i];
            v = f[v][i];
        }
    }
    ans = min(ans, min(wig[u][0], wig[v][0]));
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    init(n); kustral();
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        if (!Same(u, v)) cout << -1 << "\n";
        else cout << lca(u, v) << "\n";
    }
    return 0;
}

