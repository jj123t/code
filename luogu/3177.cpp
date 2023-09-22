/*************************************************************************
	> File Name: 3177.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 23:53:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2010;
vector<pair<int, int>> e[N];
vector<vector<int>> dp(N, vector<int>(N, -1));
int n, m;
int siz[N];
void dfs(int u, int p) {
    siz[u] = 1; dp[u][0] = dp[u][1] = 0;
    for (auto [v, w] : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        siz[u] += siz[v];
        for (int j = min(m, siz[u]); j >= 0; j--) {
            for (int k = 0; k <= min(j, siz[v]); k++) {
                if (dp[u][j - k] != -1) {
                    int a = k * (m - k) + (siz[v] - k) * (n - m - siz[v] + k);
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] + a * w);
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << dp[1][m];
    return 0;
}

