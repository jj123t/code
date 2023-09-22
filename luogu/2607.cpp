/*************************************************************************
	> File Name: 2607.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  8 10:14:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int INF = 1e9;
int par[N], dp[N][2], vis[N], w[N];
int ans = 0, root;
vector<int> e[N];
void dfs(int u) {
    vis[u] = true;
    dp[u][0] = 0, dp[u][1] = w[u];
    for (auto v : e[u]) {
        if (v != root) {
            dfs(v);
            dp[u][0] += max(dp[v][1], dp[v][0]);
            dp[u][1] += dp[v][0];
        }
        else {
            dp[u][1] = -INF;
        }
    }
}
void Find(int u) {
    vis[u] = true;
    root = u;
    while (!vis[par[root]]) {
        root = par[root];
        vis[root] = true;
    }
    dfs(root);
    int t = max(dp[root][0], dp[root][1]);
    vis[root] = true;
    root = par[root];
    dfs(root);
    ans += max(t, max(dp[root][0], dp[root][1]));
    return;
}
signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> par[i];
        e[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            Find(i);
        }
    }
    cout << ans << "\n";
    return 0;
}

