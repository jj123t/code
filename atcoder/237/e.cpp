/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 21:34:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    vector<int> w(n);
    for (auto &x : w) cin >> x;
    vector<int> e[n];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> q; q.push({0, 0}); 
    vector<int> dis(n, -1);
    while (!q.empty()) {
        auto [ww, u] = q.top(); q.pop();
        if (dis[u] != -1) continue;
        dis[u] = ww;
        for (auto v : e[u]) {
            q.push({ww + max(0ll, w[v] - w[u]), v});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, w[0] - w[i] - dis[i]);
    }
    cout << ans;
    return 0;
}

