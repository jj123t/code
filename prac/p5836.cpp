/*************************************************************************
	> File Name: p5836.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 11 Apr 2023 02:55:38 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 2e5 + 10;
vector<int> col(N, 0);
vector<int> fa(N, 0);
int par[N][21][3];
vector<int> e[N];
vector<int> dep(N, 0);
int n;
void dfs(int u, int d) {
    dep[u] = d;
    par[u][0][0] = fa[u];
    par[u][0][1] = (col[u] == 1 || col[fa[u]] == 1);
    par[u][0][2] = (col[u] == 2 || col[fa[u]] == 2);
    for (int i = 1; (1 << i) <= dep[u]; i++) {
        par[u][i][0] = par[par[u][i - 1][0]][i - 1][0];
        par[u][i][1] = (par[par[u][i - 1][0]][i - 1][1] || par[u][i - 1][1] );
        par[u][i][2] = (par[par[u][i - 1][0]][i - 1][2] || par[u][i - 1][2] );
    }
    for (auto v : e[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v, d + 1);
    }
}
int lca(int u, int v, int w) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = (int)log2(dep[v] - dep[u]); i >= 0; i--) {
        if (dep[par[v][i][0]] >= dep[u]) {
            if (par[v][i][w]) return 1;
            v = par[v][i][0];
        }
    }
    if (u == v) {
        if (col[u] == w) return 1;
        else return 0;
    }
    for (int i = (int)log2(dep[u]); i >= 0; i--) {
        if ((1 << i) <= dep[u]) {
            if (par[u][i][0] != par[v][i][0]) {
                if (par[u][i][w] || par[v][i][w]) return 1;
                u = par[u][i][0], v = par[v][i][0];
            }
        }
    }
    if (par[u][0][w] || par[v][0][w]) return 1;
    return 0;
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == 'H') col[i] = 1;
        else col[i] = 2;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v;
        char c; cin >> c;
        if (c == 'H') w = 1;
        else w = 2;
        cout << lca(u, v, w);
    }
    return 0;
}
