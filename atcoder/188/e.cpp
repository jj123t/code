/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 24 Apr 2023 01:16:45 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1); 
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> e[n + 1];
    while (m--) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    int INF = 1e17 ;
    vector<int> dp(n + 1, INF);
    for (int u = 1; u <= n; u++) {
        for (auto v : e[u]) {
            dp[v] = min({arr[u], dp[v], dp[u]});
        }
    }
    int mx = -INF;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, arr[i] - dp[i]);
    }
    cout << mx;
    return 0;
}
