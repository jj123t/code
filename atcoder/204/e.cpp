/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May  3 14:54:32 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
struct edge{
    int to, c, d;
};
signed main () {
    int n, m; cin >> n >> m;
    vector<edge> e[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        e[u].push_back({v, c, d});
        e[v].push_back({u, c, d});
    }
    using P = pair<int, int>;
    int INF = 1e17;
    vector<int> dis(n + 1, INF);
    priority_queue<P, vector<P>, greater<P>> q; q.push({0, 1});
    dis[1] = 0;
    while (!q.empty()) {
        auto [t, u] = q.top(); q.pop();
        if (t != dis[u]) continue;
        for (auto [v, c, d] : e[u]) {
            int cost = INF;
            int x = (int)sqrt(d);
            int l = max(t, x - 10ll), r = x + 10ll;
            r = max(r, l);
            for (int i = l; i <= r; i++) {
                cost = min(cost, i + c + d / (i + 1));
            }
            if (dis[v] > cost) {
                dis[v] = cost;
                q.push({dis[v], v});
            }
        }
    }
    cout << (dis[n] >= INF ? -1 : dis[n]);
    return 0;
}

