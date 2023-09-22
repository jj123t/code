/*************************************************************************
	> File Name: 4568.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 19:43:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m, k; cin >> n >> m >> k;
    const int INF = 1e18;
    vector<vector<int>> dis(n + 1, vector<int>(k + 2, INF));
    int s, t; cin >> s >> t;
    vector<array<int, 2>> e[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    q.push({0, 0, s});
    dis[s][0] = 0;
    while (!q.empty()) {
        auto [t, use, u] = q.top(); q.pop();
        for (auto [v, c] : e[u]) {
            if (use + 1 <= k and dis[v][use + 1] > dis[u][use] + 0) {
                dis[v][use + 1] = dis[u][use];
                q.push({dis[v][use + 1], use + 1, v});
            }
            if (use <= k and dis[v][use] > dis[u][use] + c) {
                dis[v][use] = dis[u][use] + c;
                q.push({dis[v][use], use, v});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, dis[t][i]); 
    cout << ans << "\n";
    return 0;
}

