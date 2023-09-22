/*************************************************************************
	> File Name: 2756.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 15:33:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
vector<int> e[N];
bool vis[N];
int match[N];
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
    int m, n; cin >> m >> n;
    int u, v; cin >> u >> v;
    while (!(u == -1 and v == -1)) {
        e[u].push_back(v);
        cin >> u >> v;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        fill(vis, vis + n + 1, 0);
        if (dfs(i)) ans++;
    }
    cout << ans << "\n";
    for (int i = m + 1; i <= n; i++) {
        if (match[i]) cout << match[i] << " " << i << "\n";
    }
    return 0;
}

