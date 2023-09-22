/*************************************************************************
	> File Name: 3379.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 03:41:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int par[N][31];
int dep[N];
vector <int> e[N];
void dfs(int u, int p) {
    dep[u] =dep[p] + 1;
    par[u][0] = p;
    for (int i = 1; i <= 30; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 30; i > -1; i--) {
        if (dep[par[u][i]] >= dep[v]) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 30; i > -1; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(s, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}

