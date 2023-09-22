/*************************************************************************
	> File Name: 3047.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 12:31:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
int c[N][21], w[N], ans[N][21];
vector<int> e[N];
int n, k;
void dfs1(int u, int p) {
    for (int i = 0; i <= k; i++) c[u][i] = w[u];
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u);
        for (int i = 1; i <= k; i++) {
            c[u][i] += c[v][i - 1];
        }
    }
}
void dfs2(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        ans[v][1] += c[u][0];
        for (int i = 2; i <= k; i++) {
            ans[v][i] += ans[u][i - 1] - c[v][i - 2];
        }
        dfs2(v, u);
    }
}
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ans[i][j] = c[i][j];
        }
    }
    dfs2(1, 0);
    for (int i = 1;  i <= n; i++) {
        cout << ans[i][k] << "\n";
    }
    return 0;
}

