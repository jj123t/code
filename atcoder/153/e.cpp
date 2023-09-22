/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 10 Apr 2023 09:02:19 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int h, n; cin >> h >> n;
    int INF = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INF));
    dp[0][0] = 0;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            if (j - w[i - 1] >= 0) 
            dp[i][j] = min(dp[i - 1][j], dp[i][j - w[i - 1]] + c[i - 1]);
            else 
            dp[i][j] = min(dp[i - 1][j], dp[i][0] + c[i - 1]);
        }
    }
    cout << dp[n][h];
    return 0;
}
