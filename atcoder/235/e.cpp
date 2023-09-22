/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 01:13:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;

vector<int> far(N, 0);
int Find(int x) {
    if (x == far[x]) return x;
    return far[x] = Find(far[x]);
}
void Unite(int x, int y) {
    far[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}

struct edge {
    int from, to, w;
};
struct node {
    int l, r, val;
}t[N];

vector<edge> tree[N];

int par[N][21];
int dep[N];
int max_[N][21];

void dfs1(int u, int p) {
    dep[u] = dep[p] + 1;
    for (auto [f, v, w] : tree[u]) {
        if (v == p) max_[u][0] = w;
        else dfs1(v, u);
    }
}
void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i <= 20; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        max_[u][i] = max(max_[u][i - 1], max_[par[u][i - 1]][i - 1]);
    }
    for (auto [a, v, w] : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int lca(int x, int y) {
    int ans = 0;
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i > -1; i--) {
        if (dep[par[x][i]] >= dep[y]) {
            ans = max(max_[x][i], ans);
            x = par[x][i];
        }
    }
    if (x == y) return ans;
    for (int i = 20; i > -1; i--) {
        if (par[x][i] != par[y][i]) {
            ans = max(ans, max_[x][i]);
            ans = max(ans, max_[y][i]);
            x = par[x][i];
            y = par[y][i];
        }
    }
    return max({ans, max_[x][0], max_[y][0]});
}

signed main()
{
    int n, m, q; cin >> n >> m >> q;
    iota(far.begin(), far.end(), 0);
    vector<edge> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    sort(e.begin(), e.end(), [&](edge a, edge b) {
         return a.w < b.w;
    });
    for (int i = 0; i < m; i++) {
        auto [u, v, w] = e[i];
        if (!Same(u, v)) {
            Unite(u, v);
            tree[u].push_back({u, v, w});
            tree[v].push_back({v, u, w});
        }
    }

    dfs1(1, 0);
    dfs(1, 0);

    while (q--) {
        int u, v, w; cin >> u >> v >> w;
        int mx = lca(u, v);
        if (mx >= w) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}

