/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat May 13 19:12:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
const int p = 998244353;

signed main()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(3010, 0));
    for (int i = a[0]; i <= b[0]; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        int l = a[i - 1];
        int r = b[i - 1];
        int tmp = 0;
        for (int j = 0; j <= r; j++) {
            tmp += dp[i - 1][j];
            tmp %= p;
            if (j >= l) {
                dp[i][j] = tmp;
                dp[i][j] %= p;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3010; i++) {
        ans += dp[n][i];
        ans %= p;
    }
    cout << ans;
    return 0;
}

