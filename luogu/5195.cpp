/*************************************************************************
	> File Name: 5195.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep  2 14:09:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                sx = i, sy = j;
            }
        }
    }
    queue<array<int, 4>> q;
    q.push({sx, sy, 0, 0});
    auto check = [&](int x, int y) -> bool {
        if (x < 0 or x >= n or y < 0 or y >= m or grid[x][y] == 1) return false;
        return true;
    };
    int ans = 1e9;
    vector<vector<int>> vis1(n + 1, vector<int>(m + 1));
    vector<vector<int>> vis2(n + 1, vector<int>(m + 1));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
        auto [x, y, s, ck] = q.front(); q.pop();
        if (ck and grid[x][y] == 3) {
            ans = min(ans, s);
            break;
        }
        if (ck) {
            if (vis2[x][y]) continue;
            vis2[x][y] = true;
        }
        else {
            if (vis1[x][y]) continue;
            vis1[x][y] = true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny) or (!ck and grid[nx][ny] == 3)) continue;
            q.push({nx, ny, s + 1, ck or grid[nx][ny] == 4});
        }
    }
    if (ans == 1e9) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
 
