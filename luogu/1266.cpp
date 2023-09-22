/*************************************************************************
	> File Name: 1266.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 19:17:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dis[160][510];
int main()
{
    int n, m, d; cin >> n >> m >> d;
    vector<array<int, 3>> e[n + 1];
    for (int i = 1; i <= m; i++) {
        int a, b, v, l; cin >> a >> b >> v >> l;
        e[a].push_back({b, v, l});
    }
    priority_queue<array<int, 3>> q;
    q.push({0, 70, 0});
    while (!q.empty()) {
        auto [t, vs, u] = q.top(); q.pop();
        for (auto [v, lim, len] : e[u]) {
            if (lim == 0) {
                if (dis[v][vs] < dis[u][vs] + len / vs) {
                    dis[v][vs] = dis[u][vs] + len / vs;
                    q.push({t + len / vs, vs, v});
                }
            }
            else {
                if (dis[v][lim] < dis[u][vs] + len / lim) {
                    dis[v][lim] = dis[u][vs] + len / lim;
                    q.push({t + len / lim, lim, v});
                }
            }
        }
    }
    return 0;
}

