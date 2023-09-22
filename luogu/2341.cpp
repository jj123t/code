/*************************************************************************
	> File Name: 2341.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 22:20:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> e[N];
stack<int> stk;
int instk[N], dfn[N], low[N], scc[N], drgee[N];
int timer, cnt;
void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk.push(u); instk[u] = true;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++cnt;
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
    using P = pair<int, int>;
    map<pair<int, int>, bool> mp;
    vector<int> edge[cnt + 1];
    for (int i = 1; i <= n; i++) {
        for (auto v : e[i]) {
            int a = scc[i];
            int b = scc[v];
            if (a != b and !mp[P(a, b)]) {
                mp[P(a, b)] = true;
                edge[a].push_back(b);
                drgee[a]++;
            }
        }
    }
    int res = 0, idx;
    for (int i = 1; i <= cnt; i++) {
        if (drgee[i] == 0) res++, idx = i;
    }
    if (res != 1) cout << 0 << "\n";
    else {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (scc[i] == idx) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

