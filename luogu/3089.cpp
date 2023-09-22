/*************************************************************************
	> File Name: 3089.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Aug  6 10:35:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;

    using P = pair<int, int>;
    vector<P> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    sort(p.begin() + 1, p.end());

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    int ans =0;
    for (int j = 1; j <= n; j++) {
        for (int i = j + 1; i <= n; i++) {
            dp[i][j] = dp[j][0] + p[j].second;
            for (int k = j - 1; k >= 1; k--) {
                if (p[i].first - p[j].first >= p[j].first - p[k].first) {
                    dp[i][j] = max(dp[i][j], dp[j][k] + p[j].second);
                }
            }
            ans = max(ans, dp[i][j] + p[i].second);
        }
    }
    for (int j = n; j >= 0; j--) {
        for (int i = j - 1; i >= 0; i--) {
            dp[i][j] = dp[j][n + 1] + p[j].second;
            for (int k = j + 1; k <= n; k++) {
                if (p[j].first - p[i].first >= p[k].first - p[j].first) {
                    dp[i][j] = max(dp[i][j], dp[j][k] + p[j].second);
                }
            }
            ans = max(ans, dp[i][j] + p[i].second);
        }
    }
    cout << ans << "\n";
    return 0;
}

