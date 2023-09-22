/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 30 Apr 2023 07:41:44 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
struct node {
    int to, t, k;
};
signed main () {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<node> e[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, t, k; cin >> u >> v >> t >> k;
        e[u].push_back({v, t, k});
        e[v].push_back({u, t, k});
    }
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, x});
    int INF = 1e18;
    vector<int> dis(n + 1, INF);
    dis[x] = 0;
    while (!q.empty()) {
        auto [w, u] = q.top(); q.pop();
        if (y == u) {
            break;
        }
        for (auto [v, t, k] : e[u]) {
            int x = ((w + k - 1) / k) * k + t;
            if (x < dis[v]) {
                dis[v] = x;
                q.push({x, v});
            }
        }
    }
    cout << (dis[y] == 1e18 ? -1 : dis[y]);
    return 0;
}

