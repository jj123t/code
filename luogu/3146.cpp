/*************************************************************************
	> File Name: 3146.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 12:39:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[300][20000];
int main()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        ans = max(dp[i][i], ans);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; i - j <= n and j >= 1; j--) {
            for (int k = j; k <= i; k++) {
                if (dp[j][k] == dp[k + 1][i] and dp[j][k]) {
                    dp[j][i] = max(dp[j][i], dp[j][k] + 1);
                    ans = max(ans, dp[j][i]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

