/*************************************************************************
	> File Name: 2746.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 09:53:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 500;
using P = pair<int, int>;
int dfn[N], low[N], timer, cnt, scc[N], instk[N], in[N], out[N];
vector<int> e[N];
stack<int> stk;
map<P, bool> mp;
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
            instk[v] = false; scc[v] = cnt;
            if (v == u) break;
        }
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (x != 0) {
            e[i].push_back(x);
            cin >> x;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : e[i]) {
            int a = scc[i]; 
            int b = scc[v];
            if (a != b and !mp[P(a, b)]) {
                mp[P(a, b)] = true;
                out[a]++;
                in[b]++;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= cnt; i++) {
        if (in[i] == 0) b++;
        if (out[i] == 0) a++;
    }
    cout << b << "\n";
    if (cnt == 1) cout << 0 << "\n";
    else cout << max(a, b) << "\n";
    return 0;
}

