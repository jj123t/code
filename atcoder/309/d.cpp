/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 19:53:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<int> e[n1 + n2];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    const int INF = 1e18;
    auto dijistra = [&](int s) {
        using P = pair<int, int>;
        queue<P> q;
        q.push(P(s, 0));
        vector<int> dis(n1 + n2, INF);
        dis[s] = 0;
        vector<int> vis(n1 + n2, 0);
        vis[s] = 1;
        while (!q.empty()) {
            auto [u, w] = q.front(); q.pop();
            for (auto v : e[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                q.push(P(v, w + 1));
                dis[v] = w + 1;
            }
        }
        return dis;
    };
    auto dis1 = dijistra(0);
    auto dis2 = dijistra(n1 + n2 - 1);
    /*
    for (int i = 0; i < n1 + n2; i++) {
        cout << dis1[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n1 + n2; i++) {
        cout << dis2[i] << " ";
    }
    */
    int mi = 0;
    for (int i = 0; i < n1; i++) {
        if (dis1[i] == INF) continue;
        mi = max(mi, dis1[i]);
    }
    int mx = 0;
    for (int i = n1; i < n1 + n2; i++) {
        if (dis2[i] == INF) continue;
        mx = max(mx, dis2[i]);
    }
    cout << (mi + mx) + 1 << "\n";
    return 0;
}

