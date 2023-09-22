/*************************************************************************
	> File Name: 2065.cpp
	> Author:123emm
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 18:54:24 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1000100;
vector<array<int, 3>> e[MAXN];
set<int> ha[MAXN];
int level[MAXN], be[MAXN];
const int INF = 1e9;
int s, t;
int n;
bool bfs() {
    for (int i = 1; i <= n; i++) level[i] = INF;
    queue<int> q; q.push(s);
    level[s] = 0, be[s] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [v, w, id] : e[u]) {
            if (w > 0 and level[v] == INF) {
                q.push(v);
                be[v] = 0; level[v] = level[u] + 1;
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int M, N, cnt = 0; cin >> M >> N;
        map<int, int> mp1, mp3;
        map<int, vector<int>> mp2;
        s = ++cnt;
        for (int i = 0; i < M; i++) {
            int x; cin >> x;
            int v = ++cnt;
            int a = e[s].size(), b = e[v].size();
            e[s].push_back({v, 1, b}); e[v].push_back({s, 0, a});

            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    while (x % j == 0) x /= j;
                    mp2[j].push_back(v);
                }
            }
            if (x > 1) mp2[x].push_back(v);
        }
        vector<int> brr(N);
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            int u = ++cnt;
            brr[i] = u;
            for (auto [p, st] : mp2) {
                if (x % p == 0) {
                    for (auto v : st) {
                        if (!ha[u].count(v) and !ha[v].count(u)) {
                            int a = e[v].size(), b = e[u].size();
                            e[v].push_back({u, 1, b});
                            e[u].push_back({v, 0, a});
                            ha[u].insert(v);
                            ha[v].insert(u);
                        }
                    }
                }
            }
        }
        t = ++cnt;
        for (auto u : brr) {
            int a = e[u].size(), b = e[t].size();
            e[t].push_back({u, 0, a});
            e[u].push_back({t, 1, b});
        }
        n = cnt;
        int ans = 0;
        while (bfs()) {
            ans += dfs(s, INF);
        }
        cout << ans << "\n";
        for (int i = 0; i <= n; i++) e[i].clear(), be[i] = 0, ha[i].clear();
    }
    return 0;
}



