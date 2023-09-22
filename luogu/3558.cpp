/*************************************************************************
	> File Name: 3558.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 14:59:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(3, INF));
    dp[1][arr[1] + 1] = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 1) {
            dp[i][0] = dp[i - 1][0] + 2;
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
        else if (arr[i] == 0) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
            dp[i][2] = dp[i - 1][2] + 1;
        }
        else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = INF;
            dp[i][2] = dp[i - 1][2] + 2;
        }
    }
    int ans = 1e9;
    for (int j = 0; j <= 2; j++) {
        ans = min(ans, dp[n][j]);
    }
    if (ans == 1e9) cout << "BRAK\n";
    else cout << ans << "\n";
    return 0;
}

