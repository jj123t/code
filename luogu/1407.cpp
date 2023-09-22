/*************************************************************************
	> File Name: 1407.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 10:29:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
map<string, int> mp;
int dfn[N], low[N], instk[N], timer, cnt, id, scc[N];
vector<int> e[N];
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
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        string a, b; cin >> a >> b;
        int ida, idb;
        if (mp[a]) ida = mp[a];
        else ida = mp[a] = ++id;
        if (mp[b]) idb = mp[b];
        else idb = mp[b] = ++id;
        e[ida].push_back(idb);
        arr[i] = {ida, idb};
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        string a, b; cin >> a >> b;
        e[mp[b]].push_back(mp[a]);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        int a = scc[arr[i].first];
        int b = scc[arr[i].second];
        if (a == b) {
            cout << "Unsafe\n";
        }
        else {
            cout << "Safe\n";
        }
    }
    return 0;
}

