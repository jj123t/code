/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 12 02:09:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
const int N = 1e6 + 10;
vector<int> par(N, 0);
void init(int n) {
    iota(par.begin(), par.begin() + n + 1, 0);
}
int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
struct edge {
    int from, to, val;
    bool operator < (const edge a) const {
        return this->val < a.val;
    }
};
signed main()
{
    int n, m; cin >> n >> m;
    init(n);
    vector<edge> a(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    sort(a.begin(), a.end());
    vector<bool> vis(m, false);
    for (int i = 0; i < m; i++) {
        int u = a[i].from, v = a[i].to, val = a[i].val;
        if (!Same(u, v)) {
            vis[i] = true;
            Unite(u, v);
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            if (a[i].val >= 0) sum += a[i].val;
        }
    }
    cout << sum;
    return 0;
}

