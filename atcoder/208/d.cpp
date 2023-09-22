/*************************************************************************
	> File Name: d.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Sat May  6 05:09:55 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	int n, m; cin >> n >> m;
	const int INF = 1e9;
	vector<vector<int>> dp(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		dp[u][v] = w;
	}
	for (int i = 0; i < n; i++) dp[i][i] = 0;
	int ans = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if (dp[i][j] < 1e9)
					ans += dp[i][j];
			}
		}
	}
	cout << ans;
    return 0;
}

