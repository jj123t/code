/*************************************************************************
	> File Name: 2763.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 21:37:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int N;
const int MAXN = 1e5;
vector<array<int, 3>> e[MAXN];
int level[MAXN], be[MAXN];
const int INF = 1e9;
int s, t;
bool bfs() {
    for (int i = 1; i <= N; i++) level[i] = INF;
    queue<int> q; q.push(s);
    level[s] = 0, be[s] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [v, w, id] : e[u]) {
            if (w > 0 and level[v] == INF) {
                q.push(v); 
                level[v] = level[u] + 1, be[v] = 0;
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
            flow -= maxnow; 
            res += maxnow;
            e[v][id][1] += maxnow;
            w -= maxnow;
        }
    }
    return res;
}
int main()
{
    int k, n; cin >> k >> n;
    vector<int> w(k + 1);
    for (int i = 1; i <= k; i++) cin >> w[i];
    s = 0, t = n + k + 1; N = t;
    for (int i = 1; i <= k; i++) {
        int u = i + n;
        int a = e[u].size(), b = e[t].size();
        e[u].push_back({t, w[i], b});
        e[t].push_back({u, 0, a});
    }
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        int a = e[s].size(), b = e[i].size();
        e[s].push_back({i, 1, b});
        e[i].push_back({s, 0, a});
        for (int j = 1; j <= p; j++) {
            int x; cin >> x; x += n;
            a = e[i].size(), b = e[x].size();
            e[i].push_back({x, 1, b});
            e[x].push_back({i, 0, a});
        }
    }
    int ans = 0;
    while (bfs()) {
        ans += dfs(s, INF);
    }
    int res = 0;
    for (int i = 1; i <= k; i++) res += w[i];
    if (ans != res) {
        cout << "No Solution!";
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        int u = n + i;
        cout << i << ": ";
        for (auto [v, w, id] : e[u]) {
            if (w == 1) {
                cout << v << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

