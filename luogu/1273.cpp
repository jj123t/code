/*************************************************************************
	> File Name: 1273.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 18:06:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 3300;
int n, m;
vector<vector<int>> dp(N, vector<int>(N, -1e9));
int son[N], w[N][N], pr[N];
vector<int> e[N];
void dfs1(int u, int p) {
    if (u != 1 and e[u].size() == 1) son[u] = 1;
    dp[u][0] = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u);
        son[u] += son[v];
    }
}
void dfs2(int u, int p) {
    if (e[u].size() == 1) dp[u][1] = pr[u];
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs2(v, u);
        for (int i = son[u]; i >= 0; i--) {
            for (int j = 0; j <= min(i, son[v]); j++) {
                dp[u][i] = max(dp[u][i], dp[v][j] + dp[u][i - j] - w[u][v]);
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, c; cin >> a >> c;
            e[a].push_back(i);
            e[i].push_back(a);
            w[a][i] = w[i][a] = c;
        }
    }
    for (int i = n - m + 1; i <= n; i++) cin >> pr[i];
    dfs1(1, 0);
    dfs2(1, 0);
    /*
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 0; j <= son[i]; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (int i = son[1]; i >= 0; i--) {
        if (dp[1][i] >= 0) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}

