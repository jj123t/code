/*************************************************************************
	> File Name: 1855.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 14:15:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, t; cin >> n >> m >> t;
    using P = pair<int, int>;
    vector<P> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    vector<vector<int>> dp(m + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= arr[i].first; j--) {
            for (int k = t; k >= arr[i].second; k--) {
                dp[j][k] = max(dp[j][k], dp[j - arr[i].first][k - arr[i].second] + 1);
            }
        }
    }
    cout << dp[m][t];
    return 0;
}

