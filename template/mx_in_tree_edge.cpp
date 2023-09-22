#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 30;
int par[N][K];
int mx[N][K];
int dep[N];
struct edge { int from, to, val; };
vector<edge> e[N];
void dfs1(int u, int p) {
    for (auto [from, to, ww] : e[u]) {
        if (to == p) mx[u][0] = ww;
        else dfs1(to, u);
    }
}
void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 20; i > -1; i--) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
    }
    for (auto [from, to, ww] : e[u]) {
        if (to == p) continue;
        dfs(to, u);
    }
}
int lca(int u, int v) {
    int res = max(mx[u][0], mx[v][0]);
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i > -1; i--) {
        if (dep[par[u][i]] >= dep[v]) {
            res = max(res, mx[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return res;
    for (int i = 20; i > -1; i--) {
        if (par[u][i] != par[v][i]) {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    return max({res, mx[u][0], mx[v][0]});
}
int main()
{
    return 0;
}

