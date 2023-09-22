/*************************************************************************
	> File Name: 3388.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 21:49:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int dfn[N], low[N], timer;
vector<int> cut;
vector<int> e[N];
int root;
void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    int son = 0;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                son++;
                if (u != root or son > 1) cut.push_back(u);
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }

}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    sort(cut.begin(), cut.end());
    cut.erase(unique(cut.begin(), cut.end()), cut.end());
    cout << cut.size() << "\n";
    for (auto v : cut) cout << v << " ";
    return 0;
}

