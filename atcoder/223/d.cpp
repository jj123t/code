/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 18:49:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    vector<int> e[n + 1];
    vector<int> in(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> q; 
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto u = q.top(); q.pop();
        ans.push_back(u);
        for (auto v : e[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    if (ans.size() < n) cout << -1;
    else for (auto x : ans) cout << x << " ";
    return 0;
}

