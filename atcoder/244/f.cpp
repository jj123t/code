/*************************************************************************
	> File Name: f.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 22:02:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> e[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push((1 << i));
        dis[i][1 << i] = 1;
    }
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            if (t >> i & 1) {
                for (auto v : e[i]) {
                    if (t >> v & 1) continue;
                    if (dis[t & (1 << v)][i] > dis[t & (1 << v)][i] + 1) {
                        dis[t & (1 << v)][i] = dis[t & (1 << v)][i] + 1;
                        q.push(t & (1 << v));
                    }
                }
            }
        }
    }
    return 0;
}

