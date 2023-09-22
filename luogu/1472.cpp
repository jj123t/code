/*************************************************************************
	> File Name: 1472.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 10:42:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[500][500];
signed main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++) dp[1][i] = 1;
    int p = 9901;
    for (int p = 1; p <= k; p++) {
        for (int i = 3; i <= n; i += 2) {
            for (int j = 1; j < i; j += 2) {
                dp[i][p] = (dp[i][p] + (dp[j][p - 1] % p) * (dp[i - j - 1][p - 1] % p) % p) % p;
            }
        }
    }
    cout << ((dp[n][k] - dp[n][k - 1] + p) % p + p) % p;
    return 0;
}

