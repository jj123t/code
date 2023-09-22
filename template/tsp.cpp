/*************************************************************************
	> File Name: tsp.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 19 22:09:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    const int INF = 1e9;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = w;
    }
    vector<vector<int>> dp((1 << n) + 1, vector<int>(n, INF));
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 1; S > -1; S--) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (!(S >> u & 1))
                dp[S][v] = min(dp[S][v], dp[S | (1 << u)][u] + d[v][u]);
            }
        }
    }
    cout << dp[0][0];
    return 0;
}

