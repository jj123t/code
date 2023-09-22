/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 05:49:48 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n; 
vector<int> e[N];
vector<int> dep(N, 0);
int par[N][30];
vector<int> son[N][30];
void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= 20; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int dfs2(int u, int st, int aim, int p) {
    if (st == 0) return son[u][aim].size() + (aim == -1);
    int ans = 0;
    for (int i = 20; i > -1; i--) {
        if (st >> i & 1) {
            for (auto v : son[u][i]) {
                if (v == p) continue;
                ans += dfs2(v, st - (1 << i), aim, par[v][0]);
            }
            break;
        }
    }
    /*
    for (auto v : e[u]) {
        if (v == p) continue;
        ans += dfs2(v, st - 1, aim, u);
    }
    */
    return ans;
}
int main () {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 20; j > -1; j--) {
            son[par[i][j]][j].push_back(i);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            cout << son[i][j] << " ";
        }
        cout << "\n";
    }
    */
    int q; cin >> q;
    while (q--) {
        int u, d; cin >> u >> d;
        //if (dep[u] > d) continue;
        int dis = d - dep[u] + 1;
        int idx = -1;
        for (int i = 20; i > -1; i--) {
            if ((1 << i) <= dis) {
                idx = i;
                break;
            }
        }
        int res = (idx == -1 ? 0 : (1 << idx));
        cout << dfs2(u, dis - res, idx, par[u][0]) << "\n";
    }
    return 0;
}
