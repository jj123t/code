/*************************************************************************
	> File Name: 1462.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 21 06:20:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
signed main()
{
    int n, m, Bl; cin >> n >> m >> Bl;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) cin >> f[i];
    vector<array<int, 3>> edges(m);
    for (auto &[a, b, c] : edges) cin >> a >> b >> c;
    using P = pair<int, int>;
    auto check = [&](int mid) -> bool {
        if (f[1] > mid or f[n] > mid) return false;
        vector<P> e[n + 1];
        for (auto [a, b, c] : edges) {
            if (f[a] <= mid and f[b] <= mid) {
                e[a].push_back(P(b, c));
                e[b].push_back(P(a, c));
            }
        }
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, 1));
        const int INF = 1e18;
        vector<int> dis(n + 1, INF);
        dis[1] = 0;
        while (!q.empty()) {
            auto [tmp, u] = q.top(); q.pop();
            if (dis[u] < tmp) continue;
            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push(P(dis[v], v));
                }
            }
        }
        return dis[n] <= Bl;
    };
    int x = *max_element(f.begin(), f.end());
    if (!check(x)) {
        cout << "AFK\n";
        return 0;
    }
    int left = 0, right = 1e10;
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << left;
        return 0;
}

