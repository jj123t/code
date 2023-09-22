/*************************************************************************
	> File Name: 2441.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 15:47:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int par[N], w[N];
vector<int> e[N];
int n;
int qry(int u, int t) {
    u = par[u];
    while (u != 0 and gcd(w[u], t) == 1) {
        u = par[u];
    }
    if (!u) return -1;
    else return u;
}
void change(int u, int x) {
    w[u] = x;
}
int main()
{
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        par[v] = u;
    }
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int u; cin >> u;
            cout << qry(u, w[u]) << "\n";
        }
        else {
            int u, a; cin >> u >> a;
            change(u, a);
        }
    }
    return 0;
}

