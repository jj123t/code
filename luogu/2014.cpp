/*************************************************************************
	> File Name: 2014.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 14:40:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> e[N];
vector<int> val(N);
int dp[1000][1000];
void dfs(int u, int p, int t) {
    if (t <= 0) return ;
    for (auto v : e[u]) {
        if (v == p) continue;
        for (int j = 0; j <= t; j++) {
            dp[v][j] = dp[u][j] + val[v];
        }
        dfs(v, u, t - 1);
        for (int j = 1; j <= t; j++) {
            dp[u][j] = max(dp[v][j - 1], dp[u][j]);
        }
    }
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, v; cin >> p >> v;
        if (p == 0) e[0].push_back(i);
        else {
            e[i].push_back(p);
            e[p].push_back(i);
        }
        val[i] = v;
    }
    dfs(0, -1, m);
    cout << dp[0][m];
    return 0;
}

