/*************************************************************************
	> File Name: d.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Sat May  6 04:14:29 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	int n, m, c; cin >> n >> m >> c;
	vector<vector<int>> e(n, vector<int>(m, 0)); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> e[i][j];
		}
	}
	long long ans = 1e18;
	const long long INF = 1e18;
	for (int k = 0; k < 2; k++) {
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				ans = min(ans, dp[i][j] + e[i][j] + c * (i + j));
				dp[i][j] = min(dp[i][j], e[i][j] - c * (i + j));
			}
		}
		reverse(e.begin(), e.end());
	}
	cout << ans;
    return 0;
}

