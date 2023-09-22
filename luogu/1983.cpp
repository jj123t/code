/*************************************************************************
	> File Name: 1983.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 09:22:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
vector<int> e[1010];
vector<int> drgee(1010);
vector<vector<bool>> vis(1010, vector<bool>(1010, 0));
queue<P> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
      for (int k = 1; k <= m; k++) {
        int len; cin >> len;
        vector<bool> pos(n + 1);
        vector<int> sit;
        for (int i = 1; i <= len; i++) {
            int x; cin >> x;
            sit.push_back(x);
            pos[x] = true;
        }
        for (int i = sit[0]; i <= sit.back(); i++) {
            if (!pos[i]) {
                for (auto v : sit) {
                    if (vis[v][i]) continue;
                    vis[v][i] = true;
                    e[v].push_back(i);
                    drgee[i]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (drgee[i] == 0) {
            q.push({i, 1});
        }
    }
    int ans = 1;
    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        for (auto v : e[u]) {
            if (--drgee[v] == 0) {
                q.push({v, d + 1});
                ans = max(ans, d + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
