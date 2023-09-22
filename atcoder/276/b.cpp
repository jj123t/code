/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 03:19:46 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    vector<int> e[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
        cout << e[i].size() << " ";
        for (auto c : e[i]) cout << c << " ";
        cout << "\n";
    }
    return 0;
}
