/*************************************************************************
	> File Name: 3758.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 19:02:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010][31];
vector<int> e[40];
const int p = 2017;
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        e[i].push_back(0);
        e[i].push_back(i);
    }
    dp[0][1] = 1;
    e[0].push_back(0);
    int t; cin >> t;
    for (int tt = 0; tt <= t; tt++) {
        for (int i = 0; i <= n; i++) {
            for (auto v : e[i]) {
                dp[tt + 1][v] = (dp[tt + 1][v] + dp[tt][i]) % p;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[t][i]) % p;
    }
    cout << ans << "\n";
    return 0;
}

