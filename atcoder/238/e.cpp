/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 17:44:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, int>;
    queue<P> q;
    vector<bool> ans(n);
    set<int> left[n + 1];
    set<int> right[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        q.push({u, v});
        left[u].insert(v);
        right[v].insert(u);
    }
    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();
        if (u == v) {
            ans[u - 1] = true;
            continue;
        }
        if (!left[u].empty()) {
            auto x = (*left[u].begin());
            if (x < v) {
                q.push({x + 1, v});
                left[x + 1].insert(v);
                right[v].insert(x + 1);
            }
            left[u].erase(left[u].begin());
        }
        if (!right[v].empty()) {
            auto y = (*(--right[v].end()));
            if (y > u) { 
                q.push({u, y - 1});
                left[u].insert(y - 1);
                right[y - 1].insert(u);
            }
            right[v].erase((--right[v].end()));
        }
    }
    bool flag = true;
    for (auto x : ans) {
        flag &= x;
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}

