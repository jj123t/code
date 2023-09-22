/*************************************************************************
	> File Name: 5905.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jun 20 06:17:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
using P = pair<int, int>;
struct edge {
    int from, to, val;
};
vector<P> e[N];
vector<edge> E;
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    for (int i = 1; i <= n; i++) {
        E.push_back({0, i , 0});
    }
    vector<int> h(n + 1, INF);
    h[0] = 0;
    for (int j = 0; j <= n; j++) {
        bool update = false;
        for (int i = 0; i < E.size(); i++) {
            if (h[E[i].to] > h[E[i].from] + E[i].val) {
                h[E[i].to] = h[E[i].from] + E[i].val;
                update = true;
                if (j == n - 1) {
                    cout << -1 << "\n";
                    return 0;
                }
            } 
        }
        if (!update) break;
    }
    for (int i = 0; i < E.size(); i++) {
        auto [u, v, w] = E[i];
        e[u].emplace_back(w + h[u] - h[v], v);
    }
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, i});
        vector<bool> vis(n + 1, false); 
        while (!q.empty()) {
            auto [w, u] = q.top(); q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto [ww, v] : e[u]) {
                if (dis[i][v] > dis[i][u] + ww) {
                    dis[i][v] = dis[i][u] + ww;
                    q.push({dis[i][v], v});
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] >= INF) ans += j * INF;
            else {
                ans += j *(dis[i][j] - h[i] + h[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

