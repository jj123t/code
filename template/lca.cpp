const int N = 1e6 + 10;
int par[N][31], dep[N];
vector<int> e[N];
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
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
    for (int i = 30; i > - 1; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
