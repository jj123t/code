/*************************************************************************
	> File Name: 1038.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 11:25:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, int>;
    vector<int> c(n + 1);
    vector<bool> vis(n + 1);
    vector<bool> out(n + 1);
    queue<int> q;
    vector<pair<int, int>> e[n + 1];
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> c[i] >> u;
        if (c[i] > 0) {
            q.push(i);
            vis[i] = true;
        }
        else c[i] -= u;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        out[u] = true;
    }
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (c[u] <= 0) continue; 
        for (auto [v, w] : e[u]) {
            c[v] += w * c[u];
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
    bool update = false;
    for (int i = 1; i <= n; i++) {
        if (!out[i] and c[i] > 0) {
            cout << i << " " << c[i] << "\n";
            update = true;
        }
    }
    if (!update) cout << "NULL";
    return 0;
}

