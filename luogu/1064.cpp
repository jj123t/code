/*************************************************************************
	> File Name: 1064.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 19 11:41:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std; 
using P = pair<int, int>;
const int N = 100;
vector<int> e[N];
vector<P> has(N);
int dp[100][50000];
int money, n;
void dfs(int u, int f, int t) {
    if (t <= 0) return;
    for (auto v : e[u]) {
        if (v == f) continue;
        auto [pric, val] = has[v];
        for (int j = money; j >= pric; j--) {
            dp[v][j - pric] = dp[u][j - pric] + pric * val;
        }
        dfs(v, u, t - pric);
        for (int j = money; j >= pric; j--) {
            dp[u][j] = max(dp[u][j], dp[v][j - pric]);
        }
    }
}
int main()
{
    cin >> money >> n;
    for (int i = 1; i <= n; i++) {
        int v, p, q; cin >> v >> p >> q;
        e[q].push_back(i);
        e[i].push_back(q);
        has[i] = P(v, p);
    }
    dfs(0, -1, money);
    int ans = 0;
    for (int i = 0; i <= money; i++) {
        ans = max(ans, dp[0][i]);
    }
    cout << ans << "\n";
    return 0;
}

