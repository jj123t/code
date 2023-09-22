/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 21:20:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
vector<int> e[N];
map<int, int> mp;
int ans = 0;
void dfs(int u, int p, int s) {
    int t = max(s, mp[u]);
    if (t) ans++;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u, max(t - 1, 0ll));
    }
}
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        mp[x] = max(mp[x], y + 1);
    }
    dfs(1, 0, mp[1]);
    cout << ans <<'\n';
    return 0;
}

