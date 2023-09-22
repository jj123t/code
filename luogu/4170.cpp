/*************************************************************************
	> File Name: 4170.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 20:23:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            if (s[i] == s[j]) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
            else {
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}

