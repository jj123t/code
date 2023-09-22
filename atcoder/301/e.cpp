/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 04:37:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long
using P = pair<int, int>;
const int N = 400;
vector<string> e(N);
P S, G;
signed main()
{
    int n, m, t; cin >> n >> m >> t;
    for (int i = 0; i < n; i++) cin >> e[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (e[i][j] == 'S') S = P(i, j);
            if (e[i][j] == 'G') G = P(i, j);
        }
    }
    using tp = tuple<int, int, int, int, set<P>>;
    priority_queue<tp> q; q.push({0, 0, S.first, S.second, {}});
    int ans = 0;
    bool flag = false;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    auto check = [&](int x, int y) -> bool {
        return (x < 0 || x >= n || y < 0 || y >= m || e[x][y] == '#');
    };
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    map<set<P>, int> mp[n + 1][m + 1];
    while (!q.empty()) {
        auto [tmp, fd, rtx, rty, st] = q.top(); q.pop();
        if (tmp > t) continue; 
        if (mp[rtx][rty][st] && mp[rtx][rty][st] < tmp) continue;
        if (mp[rtx][rty][st])
            mp[rtx][rty][st] = min(mp[rtx][rty][st], tmp);
        else 
            mp[rtx][rty][st] = tmp;
        if (P(rtx, rty) == G) {
            ans = max(ans, fd);
            flag = true;
        }
        for (int i = 0; i < 4; i++) {
            int rx = rtx + dx[i];
            int ry = rty + dy[i];
            if (check(rx, ry)) continue;
            if (vis[rx][ry] >= 1000) continue;
            vis[rx][ry]++;
            bool dol = false;
            if (e[rx][ry] == 'o' && !st.count(P(rx, ry))) {
                fd++;
                st.insert(P(rx, ry));
                dol = true;
            }
            q.push({tmp + 1, fd, rx, ry, st});
            if (dol) {
                fd--;
                st.erase(P(rx, ry));
            }
        }
    }
    cout << (flag ? ans : -1);
    return 0;
}


