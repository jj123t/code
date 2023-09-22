/*************************************************************************
	> File Name: 1352.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 15:50:03 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 6e4;
vector<int> w(N);
vector<vector<int>> dp(N, vector<int>(2, 0));
vector<int> e[N];
void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}

