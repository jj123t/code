/*************************************************************************
	> File Name: 1197.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 19:22:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> par(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    init(n);
    vector<int> e[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int k; cin >> k;
    vector<int> qry(k);
    set<int> mp;
    for (int i = 0; i < k; i++) { 
        cin >> qry[i];
        mp.insert(qry[i]);
    }
    reverse(qry.begin(), qry.end());
    int ans = n;
    for (int u = 0; u < n; u++) {
        if (mp.count(u)) continue;
        for (auto v : e[u]) {
            if (mp.count(v)) continue;
            if (!same(u, v)) {
                ans--;
                Unite(u, v);
            }
        }
    }
    stack<int> stk;
    set<int> st;
    for (int i = 0; i < k; i++) st.insert(qry[i]);
    stk.push(ans - k);
    for (int i = 0; i < k; i++) {
        int u = qry[i];
        st.erase(u);
        for (auto v : e[u]) {
            if ((st.empty() or !st.count(v)) and !same(u, v)) {
                ans--;
                Unite(u, v);
            }
        }
        stk.push(ans - (k - i - 1));
    }
    while (!stk.empty()) {
        cout << stk.top() << "\n";
        stk.pop();
    }
    return 0;
}

