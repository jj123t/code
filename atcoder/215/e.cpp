/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May  8 23:09:35 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int dp[1020][1030][11];
const int p = 998244353;
signed main () {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - 'A';
        for (int st = 0; st < (1 << 10); st++) {
            for (int j = 0; j < 10; j++) {
                dp[i][st][j] = dp[i - 1][st][j];
                if (j == x) dp[i][st][j] = (dp[i][st][j] + dp[i -1][st][j]) % p;
            }
        }
        for (int st = 0; st < (1 << 10); st++) {
            if (st >> x & 1) continue;
            for (int k = 0; k < 10; k++) 
                dp[i][st | (1 << x)][x] = (dp[i][st | (1 << x)][x] + dp[i - 1][st][k]) % p;
        }
        dp[i][(1 << x)][x]++;
        dp[i][(1 << x)][x] %= p;
    }
    int ans = 0;
    for (int i = 0; i < (1 << 10); i++) {
        for (int k = 0; k < 10; k++) {
            ans += dp[n][i][k];
            ans %= p;
        }
    }
    cout << ans;
    return 0;
}
