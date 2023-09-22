/*************************************************************************
	> File Name: 2863.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 22:58:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> e[N];
int dfn[N], low[N], instk[N], dg[N], scc[N], timer, cnt;
stack<int> stk;
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
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        dg[scc[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (dg[i] > 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}

