/*************************************************************************
	> File Name: 1879.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 21:55:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[200][10000];
int g[200];
signed main()
{
    const int p = 1e8;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (x == 0) res += (1ll << j);
        }
        g[i] = res;
    }
    vector<int> avl[(1ll << 12) + 1];
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (!(i & j)) {
                avl[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        if ((i & g[1]) or ((i << 1) & i) or ((i >> 1) & i)) continue;
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int now = 0; now < (1 << m); now++) {
            if (((now << 1ll) & now) or (now & g[i]) or ((now >> 1) & now)) continue;
            for (auto last : avl[now]) {
                if (((last << 1ll) & last) or (last & g[i - 1]) or ((last >> 1) & last)) continue;
                dp[i][now] = (dp[i][now] + dp[i - 1][last]) % p;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < (1 << m); j++) {
        ans = (ans + dp[n][j]) % p;
    }
    cout << ans << "\n";
    return 0;
}

