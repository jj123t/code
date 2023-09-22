/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 15:13:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    const int p = 998244353;
    int n, m, k, s, t, x; cin >> n >> m >> k >> s >> t >> x;
    using P = pair<int, int>;
    vector<P> e(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e.push_back({u, v});
        e.push_back({v, u});
    }
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    dp[0][s][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (auto [u, v] : e) {
            if (u == x) {
                dp[i][u][1] += dp[i - 1][v][0];
                dp[i][u][1] %= p;
                dp[i][u][0] += dp[i - 1][v][1];
                dp[i][u][0] %= p;
            }
            else {
                dp[i][u][0] += dp[i - 1][v][0]; 
                dp[i][u][0] %= p;
                dp[i][u][1] += dp[i - 1][v][1];
                dp[i][u][1] %= p;
            }
        }
    }
    /*
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }
    */
    cout << dp[k][t][0] % p;
    return 0;
}

