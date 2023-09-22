/*************************************************************************
	> File Name: 3605.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 21:09:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int tree[N];
int n;
vector<int> e[N];
void add(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
}
int qry(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
vector<int> power(N);
vector<int> ans(N);
void dfs(int u, int p) {
    int last = qry(power[u]);
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    } 
    ans[u] = qry(power[u]) - last;
    add(power[u], 1);
}
int main()
{
    cin >> n;
    int cnt = n;
    map<int, int> mp;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
        st.insert(power[i]);
    }
    for (auto c : st) mp[c] = cnt--;
    for (int i = 1; i <= n; i++) power[i] = mp[power[i]];
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}

