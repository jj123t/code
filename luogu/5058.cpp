/*************************************************************************
	> File Name: 5058.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 10:43:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5;
int dfn[N], low[N], timer;
int a, b, root;
vector<int> e[N], cut;
void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                if (u != root and dfn[b] >= dfn[v]) {
                    cut.push_back(u);
                }
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; ; i++) {
        int u, v; cin >> u >> v;
        if (u == 0 and v == 0) break;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> a >> b;
    root = a; 
    tarjan(a);
    sort(cut.begin(), cut.end());
    if (cut.size() == 0) cout << "No solution";
    else {
        cout << cut[0] << "\n";
    }
    return 0;
}

