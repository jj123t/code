/*************************************************************************
	> File Name: 2515.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 13:54:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int dfn[N], low[N], timer, cnt, instk[N], w[N], v[N], waf[N], vaf[N];
int in[N];
vector<int> scc(N);
int dp[N][1000];
stack<int> stk;
using P = pair<int, int>;
map<P, bool> mp;
int n, m;
vector<int> e[N], edge[N];
void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk.push(u); instk[u] = true;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        cnt++;
        while (true) {
            int v = stk.top(); stk.pop();
            instk[v] = false;
            scc[v] = cnt;
            if (v == u) break;
        }
    }
}
void dfs(int u, int p) {
    for (int i = waf[u]; i <= m; i++) {
        dp[u][i] = vaf[u];
    }
    for (auto v : edge[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = m - waf[u]; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[u][i + waf[u]] = max(dp[u][i + waf[u]], dp[v][j] + dp[u][i + waf[u] - j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        if (d) {
            e[d].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        waf[scc[i]] += w[i];
        vaf[scc[i]] += v[i];
        for (auto v : e[i]) {
            int a = scc[i];
            int b = scc[v];
            if (a != b and !mp[P(a, b)]) {
                mp[P(a, b)] = true;
                edge[a].push_back(b);
                in[b]++;
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (in[i] == 0) edge[0].push_back(i);
    }
    dfs(0, 0);
    cout << dp[0][m] << "\n";
    return 0;
}

