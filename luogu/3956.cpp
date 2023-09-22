/*************************************************************************
	> File Name: 3956.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 21 09:53:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n; cin >> m >> n;
    vector<vector<int>> g(m + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        int x, y, c; cin >> x >> y >> c;
        c++;
        g[x][y] = c;
    }
    using ar = array<int, 5>;
    priority_queue< ar, vector<ar>, greater<ar> > q;
    int vis[m + 1][m + 1][3];
    memset(vis, false, sizeof vis) ;
    int ans = 1e9;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    q.push({0, 1, 1, g[1][1], 0});
    while (!q.empty()) {
        auto [s, x, y, cr, used] = q.top(); q.pop();
        if (x == m and y == m) {
            ans = min(ans, s);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 >= nx or nx > m or 0 >= ny or ny > m) continue;
            if (used) {
                if (g[nx][ny] == cr) q.push({s, nx, ny, cr, 0});
                else if (g[nx][ny] != 0) q.push({s + 1, nx, ny, g[nx][ny], 0});
            }
            else {
                if (g[nx][ny] == cr) q.push({s, nx, ny, cr, 0});
                else if (g[nx][ny] == 0) {
                    q.push({s + 2, nx, ny, 1, 1});
                    q.push({s + 2, nx, ny, 2, 1});
                }
                else {
                    q.push({s + 1, nx, ny, g[nx][ny], 0});
                }
            }
        }
    }
    if (ans == 1e9) cout << -1 << "\n";
    else cout << ans << '\n';
    return 0;
}

