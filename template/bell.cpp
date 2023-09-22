/*************************************************************************
	> File Name: bell.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 19 21:47:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int mod = 10000; 
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % mod;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n];
    return 0;
}

