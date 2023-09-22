/*************************************************************************
	> File Name: 1514.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  1 13:48:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    using P = pair<int, int>;
    vector<P> st(m + 1);
    for (int i = 1; i <= m; i++) st[i].first = 1e9, st[i].second = -1;
    auto check = [&](int x, int y) -> bool {
        if (x <= 0 or x > n or y <= 0 or y > m) return false;
        return true;
    };
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> res(m + 1);
    for (int i = 1; i <= m; i++) {
        queue<P> q;
        q.push({1, i});
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = true;
            if (x == n) { 
                res[y] = true;
                st[i].first = min(st[i].first, y);
                st[i].second = max(st[i].second, y);
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (check(nx, ny)) {
                    if (grid[nx][ny] < grid[x][y]) {
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    vector<int> can(m + 1);
    for (int i = 1; i <= m; i++) {
        auto [x, y] = st[i];
        if (x == 1e9 and y == -1) continue;
        can[x] = max(can[x], y);
    }
    int ans = 0;
    const int INF = 1e9;
    vector<vector<int>> dp(m + 1, vector<int>(2, INF));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= m; i++) {
        if (can[i])
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        for (int j = 1; j < i; j++) {
            if (can[j] >= i)
            dp[i][0] = min(dp[i][0], dp[j][1]);
        }
    }
    int flag = 0;
    for (int i = 1; i <= m; i++) {
        if (!res[i]) flag++;
    }
    if (flag) cout << 0 << "\n" << flag << '\n';
    else cout << 1 << '\n' << min(dp[m][1], dp[m][0]) << "\n";
    return 0;
}
