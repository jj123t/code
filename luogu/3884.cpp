/*************************************************************************
	> File Name: 3884.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 18:36:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> e[N];
vector<int> dep(N);
vector<vector<int>> par(N, vector<int>(21, 0));
vector<int> wid(N);
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    wid[dep[u]]++;
    par[u][0] = p;
    for (int i = 1; i <= 20; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dep[par[x][i]] >= dep[y]) {
            x = par[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;  cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int u, v; cin >> u >> v;
    int d = *max_element(dep.begin(), dep.begin() + n + 1);
    int w = *max_element(wid.begin(), wid.begin() + n + 1);
    int LCA = lca(u, v);
    int ans = (dep[u] - dep[LCA]) * 2 + (dep[v]) - (dep[LCA]);
    cout << d << "\n" << w << "\n" << ans << "\n";
    return 0;
}

