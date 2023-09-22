/*************************************************************************
	> File Name: 2057.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 12:05:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m, s, t;
int level[N], now[N], be[N];
vector<array<int, 3>> e[N];
const int INF = 1e9;
bool bfs() {
    for (int i = 1; i <= n; i++) level[i] = INF;
    queue<int> q; q.push(s);
    level[s] = 0; be[s] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [v, w, id] : e[u]) {
            if (w > 0 and level[v] == INF) {
                q.push(v);
                be[v] = 0;
                level[v] = level[u] + 1;
                if (v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, int flow) {
    if (u == t or !flow) return flow;
    int res = 0;
    for (int i = be[u]; i < e[u].size(); i++) {
        be[u] = i;
        auto &[v, w, id] = e[u][i];
        if (w > 0 and level[v] == level[u] + 1) {
            int maxnow = dfs(v, min(flow, w));
            if (maxnow == 0) level[v] = INF;
            w -= maxnow;
            e[v][id][1] += maxnow;
            res += maxnow;
            flow -= maxnow;
        }
    }
    return res;
}
void add(int u, int v, int w) {
    int a = e[u].size(), b = e[v].size();
    e[u].push_back({v, w, b});
    e[v].push_back({u, 0, a});
}
int main()
{
    cin >> n >> m;
    s = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) {
            add(s, i, 1);
        }
        else {
            add(i, t, 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        add(u, v, 1);
        add(v, u, 1);
    }
    n++;
    int ans = 0;
    while (bfs()) {
        ans += dfs(s, INF);
    }
    cout << ans << "\n";
    return 0;
}

