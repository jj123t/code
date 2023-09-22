/*************************************************************************
	> File Name: 1787c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 23:34:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, s; cin >> n >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<vector<int>> xy(n + 1, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            if (i == 0 or i == n - 1) xy[i][0] = xy[i][1] = arr[i];
            else {
                if (arr[i] >= s) xy[i][0] = s, xy[i][1] = arr[i] - s;
                else xy[i][0] = 0, xy[i][1] = arr[i];
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = xy[0][0] * xy[1][0];
        dp[0][1] = xy[0][0] * xy[1][1];
        for (int i = 1; i < n - 1; i++) {
            dp[i][0] = min(dp[i - 1][0] + xy[i][1] * xy[i + 1][0], dp[i - 1][1] + xy[i][0] * xy[i + 1][0]);
            dp[i][1] = min(dp[i - 1][0] + xy[i][1] * xy[i + 1][1], dp[i - 1][1] + xy[i][0] * xy[i + 1][1]);
        }
        cout << min(dp[n - 2][0], dp[n - 2][1]) << "\n";
    }
    return 0;
}

