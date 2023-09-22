/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 30 13:11:45 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(11, 0));
    const int p = 998244353;
    for (int i = 1; i <= 9; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % p;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % p;
            dp[i][j] = (dp[i][j] + dp[i -1][j +1]) % p;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans = (ans + dp[n - 1][i] ) % p;
    }
    cout << ans << "\n";
 
    return 0;
}

