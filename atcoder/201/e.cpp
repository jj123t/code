/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 04:53:46 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int p = 1e9 + 7;
signed main () {
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> e[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector<int> d(n + 1, 0);
    queue<int> q; q.push(1);
    vector<int> vis(n + 1, false);
    vis[1] = true;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [v, w]: e[u]) {
            if (vis[v])  continue;
            vis[v] = true;
            d[v] = d[u] ^ w;
            q.push(v);
        }
    }
    int ans = 0;
    for (int i = 0; i < 60; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (d[j] >> i & 1) res++;
        }
        ans += (1ll << i) % p * res % p * (n - res) % p;
        ans %= p;
    }
    cout << ans;
    return 0;
}
