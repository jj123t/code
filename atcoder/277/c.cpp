/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 03:51:14 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    map<int, vector<int>> e;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 1;
    queue<int> q;
    q.push(1);
    map<int, int> vis;
    vis[1] = true;
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        for (auto v : e[x]) {
            if (vis[v]) continue;
            vis[v] = true;
            ans = max(v, ans);
            q.push(v);
        }
    }
    cout << ans;
    return 0;
}
