#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 30;
int par[N][K];
int mx[N][K];
int dep[N];
struct edge { int from, to, val; };
vector<edge> e[N];
vector<int> w(N);
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    par[x][0] = fa;
    mx[x][0] = w[fa]; 
    for (int i = 1; i <= 20; i++) {
        par[x][i] = par[par[x][i - 1]][i - 1];
        mx[x][i] = max(mx[x][i - 1], mx[par[x][i - 1]][i - 1]);
    }
    for (auto [from, to, ww] : e[x]) {
        if (to == fa) continue;
        dfs(to, x);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int res = 0;
    for (int i = 20; i > -1; i--) {
        if (dep[par[u][i]] >= dep[v]) {
            res = max(res, mx[u][i]);
            u = par[u][i];
        }
    }
    if (v == u) return res;
    for (int i = 20; i > -1; i--) {
        if (par[u][i] != par[v][i]) {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    return max({res, mx[v][0], mx[u][0]});
}
int main()
{

    return 0;
}

