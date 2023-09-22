/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 23:28:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N = 1e6 + 10;
vector<int> e[N];
vector<int> par(N, 0);
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
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0;
    iota(par.begin(), par.begin() + n + 1, 0);
    set<int> st;
    stack<int> stk;
    for (int i = n; i >= 1; i--) {
        stk.push(ans);
        ans++;
        st.insert(i);
        set<int> mp;
        for (auto v : e[i]) {
            if (st.count(v) && !Same(v, i)) {
                ans--;
                Unite(v, i);
            }
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << "\n";
        stk.pop();
    }
    return 0;
}

