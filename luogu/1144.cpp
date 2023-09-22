/*************************************************************************
	> File Name: 1144.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 21 05:53:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    const int p = 100003;
    int n, m; cin >> n >> m;
    vector<int> e[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (v == u) continue;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    using P = pair<int, int>;
    queue<P> q; q.push({1, 0});
    vector<int> ans(n + 1, 0);
    vector<int> dis(n + 1, 0);
    vector<int> vis(n + 1, false);
    vis[1] = true;
    ans[1] = 1;
    while (!q.empty()) {
        auto [u, w] = q.front(); q.pop();
        for (auto v : e[u]) {
            if (vis[v]) {
                if (dis[v] == w + 1) {
                    ans[v] = (ans[v] + ans[u]) % p;
                }
            }
            else {
                vis[v] = true;
                q.push({v, w + 1});
                dis[v] = w + 1;
                ans[v] = (ans[v] + ans[u]) % p;
            }
        }
    }
    for (int i = 1; i < ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}

