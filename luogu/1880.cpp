/*************************************************************************
	> File Name: 1880.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 14:45:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> arr(2 * n + 1); 
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) arr[i + n] = arr[i];
    vector<int> pfx(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        pfx[i] = pfx[i - 1] + arr[i];
    }
    const int INF = 1e18;
    vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1, 0));
    vector<vector<int>> dp1(2 * n + 1, vector<int>(2 * n + 1, INF));
    for (int i = 1; i <= 2 * n; i++) dp1[i][i] = 0;
    for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + pfx[j] - pfx[i - 1]);
                dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + pfx[j] - pfx[i - 1]);
            }
        }
    }
    int ans1 = 0;
    int ans2 = INF;
    for (int i = 1; i <= n; i++) {
        ans1 = max(ans1, dp[i][n + i - 1]);
        ans2 = min(ans2, dp1[i][n + i - 1]);
    }
    cout << ans2 << "\n" << ans1 << "\n";
    return 0;
}

