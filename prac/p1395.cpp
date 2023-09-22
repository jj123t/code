/*************************************************************************
	> File Name: p1395.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 10:34:20 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
vector<int> e[N];
vector<int> siz(N, 0);
vector<int> dis(N, 0);
vector<int> fa(N, 0);
void dfs(int u, int d) {
    for (auto v : e[u]) {
        if (v == fa[u]) continue;
        siz[u]++;
        fa[v] = u;
        dfs(v, d + 1);
        siz[u] += siz[v];
    }
    dis[1] += d;
}
int n;
void dfs2(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        dis[v] = dis[u] + n - 2 * siz[v] - 2;
        dfs2(v, u);
    }
}
int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int mx = 1e9, idx = 0;
    for (int i = 1; i <= n; i++) {
        if (mx > dis[i]) {
            mx = dis[i];
            idx = i;
        }
    }
    cout << idx << " " << mx;
    return 0;
}
