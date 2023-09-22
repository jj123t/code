/*************************************************************************
	> File Name: p4017.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 26 Apr 2023 01:22:46 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 80112002;
#define int long long 
signed main () {
    int n, m; cin >> n >> m;
    vector<int> dp(n + 1, 0);
    vector<int> in(n + 1, 0), out(n + 1, 0);
    vector<int> e[n + 1]; 
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : e[u]) {
            in[v]--;
            dp[v] = (dp[v] + dp[u]) % p;
            if (!in[v]) q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            ans = (ans + dp[i]) % p;
        }
    }
    cout << ans;
    return 0;
}
