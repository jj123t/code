/*************************************************************************
	> File Name: 5322.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 16:30:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[105][40000];
int main()
{
    int s, n, m; cin >> s >> n >> m;
    vector<int> arr[n + 1];
    for (int i = 1; i <= n; i++) arr[i].push_back(0);
    for (int i = 0; i < s; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            arr[j].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) sort(arr[i].begin(), arr[i].end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= s; k++) {
                int d = 2 * arr[i][k] + 1;
                if (k == 0) d = 0;
                if (j + d > m) continue;
                dp[i][j] = max(dp[i - 1][j + d] + k * i, dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

