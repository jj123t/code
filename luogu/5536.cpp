/*************************************************************************
	> File Name: 5536.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 18:05:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> e[N];
vector<int> pre(N), dep(N), fa(N);
void dfs1(int u, int p) {
    dep[u] = dep[p] + 1;
    pre[u] = p;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u);
    }
}
vector<int> res(N);
void dfs2(int u, int p) {
    if (e[u].size() == 1) dep[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs2(v, u);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}
int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs1(1, 0);
    int ua = max_element(dep.begin() + 1, dep.begin() + n + 1) - dep.begin();
    fill(dep.begin(), dep.end(), 0);
    dfs1(ua, 0);
    int ub = max_element(dep.begin() + 1, dep.begin() + n + 1) - dep.begin();
    for (int i = 1; i <= dep[ub] / 2 + 1; i++) {
        ub = pre[ub];
    }
    int root = ub;
    fill(dep.begin(), dep.end(), 0);
    dfs2(root, 0);
    sort(dep.begin() + 1, dep.begin() + n + 1);
    reverse(dep.begin() + 1, dep.begin() + n + 1);
    cout << dep[k + 1] << "\n";
    return 0;
}

