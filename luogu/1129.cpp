/*************************************************************************
	> File Name: 1129.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 16:01:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 101000;
vector<int> e[N];
vector<int> match(N), vis(N);
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
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x; cin >> x;
                if (x == 1) {
                    e[i].push_back(j + n);
                    e[j + n].push_back(i);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            fill(vis.begin(), vis.end(), false);
            if (dfs(i)) ans++;
        }
        if (ans >= n) cout << "Yes" << "\n";
        else cout << "No" << "\n";
        for (int i = 1; i <= n * 2 + 1; i++) e[i].clear();
        for (int i = 1; i <= 2 * n + 1; i++) vis[i] = false, match[i] = 0;
    }
    return 0;
}

