/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 25 Apr 2023 08:20:40 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 1e6 + 10;
int n; 
map<int, int> mp;
vector<int> e[N];
vector<int> w(N, 0);
vector<int> ans;
void dfs(int u, int p) {
    if (!mp[w[u]]) ans.push_back(u);
    mp[w[u]]++;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    mp[w[u]]--;
}
signed main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << "\n";
    return 0;
}
