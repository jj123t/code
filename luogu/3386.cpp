/*************************************************************************
	> File Name: 3386.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 15:18:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> e[N];
int vis[N], match[N];
bool dfs(int u) {
    for (auto v : e[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (!match[v] or dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, 0);
        if (dfs(i)) ans++;
    }
    cout << ans << "\n";
    return 0;
}

