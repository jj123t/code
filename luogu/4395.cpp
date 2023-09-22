/*************************************************************************
	> File Name: 4395.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 23:03:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[100100][16];
vector<int> e[100100];
void dfs(int u, int p) {
    for (int i = 1; i <= 15; i++) {
        dp[u][i] = i;
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 1; i <= 15; i++) {
            int res = 1e9;
            for (int j = 1; j <= 15; j++) {
                if (j == i) continue;
                res = min(res, dp[v][j]);
            }
            dp[u][i] += res;
        }
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 1e9;
    for (int i = 1; i <= 15; i++) {
        ans = min(ans, dp[1][i]);
    }
    cout << ans << "\n";
    return 0;
}
