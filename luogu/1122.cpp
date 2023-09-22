/*************************************************************************
	> File Name: 1122.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 16:38:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
vector<int> w(N);
vector<int> e[N];
vector<int> dp(N, -1e18);
void dfs(int u, int p) {
    dp[u] = w[u];
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dp[v] >= 1) dp[u] += dp[v];
    }
}
signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}

