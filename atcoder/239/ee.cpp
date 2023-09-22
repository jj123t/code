/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 19 04:51:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> c[N];
vector<int> e[N];
void dfs(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (auto x : c[v]) {
            c[u].push_back(x);
        }
    }
    sort(c[u].rbegin(), c[u].rend());
    while (c[u].size() > 20) c[u].pop_back();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c[i].push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, 0);
    while (q--) {
        int u, k; cin >> u >> k;
        u--;
        cout << c[u][k - 1] << '\n';
    }
    return 0;
}


