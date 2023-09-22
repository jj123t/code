/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 20 Apr 2023 05:54:59 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll n, m; cin >> n >> m;
    vector<ll> A(n), B(m);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    ll INF = 1e18;
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) { 
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (i < n && j < m) {
                dp[i + 1][j + 1] = min(dp[i][j] + (A[i] != B[j]), dp[i + 1][j + 1]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
