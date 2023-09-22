/*************************************************************************
	> File Name: 1896.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 09:44:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[15][15][4000];
signed main()
{
    int n, k; cin >> n >> k;
    vector<int> avl[(1 << n) + 1];
    for (int i = 0; i < (1 << n); i++) {
        if (((i >> 1) & i) or (i << 1) & i) continue;
        for (int j = 0; j < (1 << n); j++) {
            if (((j >> 1) & j) or ((j << 1) & j)) continue;
            if (__builtin_popcount(i) > k or __builtin_popcount(j) > k) continue;
            if (i & j) continue;
            if (((j >> 1) & i) or ((j << 1) & i) or ((i >> 1) & j) or ((i << 1) & j)) continue;
            avl[i].push_back(j);
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int now = 0; now < (1 << n); now++) {
            for (int last : avl[now]) {
                for (int j = 0; j <= k; j++) {
                    int cnt = __builtin_popcount(now);
                    if (j < cnt) continue;
                    dp[i][j][now] += dp[i - 1][j - cnt][last];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans += dp[n][k][i];
    }
    cout << ans << "\n";
    return 0;
}

