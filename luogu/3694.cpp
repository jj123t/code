/*************************************************************************
	> File Name: 3694.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 14:32:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e7;
int dp[N], sum[N][21], s[N], arr[N];
signed main()
{
    fill(dp, dp + N, 1e9 + 7);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + (arr[i] == j);
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                s[i] += sum[n][j + 1];
            }
        }
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) { 
            if (i >> j & 1) {
                int l = s[i ^ (1 << j)], r = s[i];
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + sum[n][j + 1] - sum[r][j + 1] + sum[l][j + 1]);
            }
        }
    }
    cout << dp[(1 << m) - 1];
    return 0;
}

