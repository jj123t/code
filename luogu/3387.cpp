/*************************************************************************
	> File Name: 3387.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 20:01:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int dfn[N], low[N], instk[N];
int timer, cnt;
stack<int> stk;
vector<int> e[N];
int scc[N];
int w[N];
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
    if (low[u] == dfn[u]) {
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
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    vector<int> rnk(cnt + 1);
    vector<int> edge[cnt + 1];
    using P = pair<int, int>;
    map<P, bool> mp;
    for (int i = 1; i <= n; i++) {
        rnk[scc[i]] += w[i];
        for (auto v : e[i]) {
            int a = scc[i];
            int b = scc[v];
            if (a != b and !mp[P(a, b)]) {
                mp[P(a, b)] = true;
                edge[b].push_back(a);
            }
        }
    }
    int ans = 0;
    for (int u = cnt; u >= 1; u--) {
        int res = 0;
        for (auto v : edge[u]) {
            res = max(res, rnk[v]);
        }
        rnk[u] += res;
        ans = max(ans, rnk[u]);
    }
    cout << ans << "\n";
    return 0;
}

