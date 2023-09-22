/*************************************************************************
	> File Name: 1867d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 23:11:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> e[N];
vector<int> pre(N);
int k, flag = true;
vector<int> vis(N);
vector<int> dfn(N);
int timer = 0;
void dfs(int u) {
    dfn[u] = ++timer;
    for (auto v : e[u]) {
        if (vis[v]) {
            int t = u;
            int cnt = dfn[u] - dfn[v] + 1;
            if (cnt != k) {
                flag = false;
                return ;
            }
        }
        else {
            vis[v] = true;
            pre[v] = u;
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n >> k;
        flag = true;
        fill(vis.begin(), vis.end(), false);
        fill(pre.begin(), pre.end(), 0);
        vector<int> arr(n + 1), brr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            e[i].push_back(arr[i]);
        }
        if (!flag) {
            cout << "NO\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        if (flag) cout << "YES\n";
        else cout << "No\n";
        for (int i = 1; i <= n; i++) e[i].clear();
    }
    return 0;
}

