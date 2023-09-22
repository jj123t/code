/*************************************************************************
	> File Name: 1126.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  1 12:02:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            if (x == 1) {
                grid[i][j] = grid[i - 1][j] = grid[i][j - 1] = grid[i - 1][j - 1] = 1;
            }
        }
    }
    int sx, sy, tx, ty; char face; cin >> sx >> sy >> tx >> ty >> face;
    queue<array<int, 4>> q;
    map<array<int, 3>, bool> mp;
    q.push({sx, sy, face - 'A', 0});
    using P = pair<int, int>;
    auto check = [&](int x, int y) -> bool {
        if (x <= 0 or x >= n or y <= 0 or y >= m or grid[x][y] == 1) return false;
        return true;
    };
    auto trans = [&](int x, int y, char c, int d) -> P {
        int nx = x, ny = y;
        if (c == 'E') ny += d;
        else if (c == 'S') nx += d;
        else if (c == 'W') ny -= d;
        else nx -= d;
        bool flag = true;
        for (int i = min(x, nx); i <= max(x, nx); i++) {
            for (int j = min(y, ny); j <= max(y, ny); j++) {
                if (!check(i, j)) {
                    flag = false;
                }
            }
        }
        if (flag) return P(nx, ny);
        else return P(-1, -1);
    };
    auto change_right = [&](char c) -> char {
        if (c == 'E') return 'S';
        else if (c == 'W') return 'N';
        else if (c == 'S') return 'W';
        else return 'E';
        return ' ';
    };
    auto change_left = [&](char c) -> char {
        if (c == 'E') return 'N';
        else if (c == 'W') return 'S';
        else if (c == 'S') return 'E';
        else return 'W';
        return ' ';
    };
    int ans = 1e17;
    while (!q.empty()) {
        auto [x, y, f, s] = q.front(); q.pop();
        if (x == tx and y == ty) {
            ans = min(ans, s);
        }
        if (mp[{x, y, f}]) continue;
        mp[{x, y, f}] = true;
        {
            for (int i = 1; i <= 3; i++) {
                auto [nx, ny] = trans(x, y, f + 'A', i);
                if (!check(nx, ny) or P(nx, ny) == P(-1, -1)) continue;
                q.push({nx, ny, f, s + 1});
            }
        }
        {
            q.push({x, y, change_right(f + 'A') - 'A', s + 1});
            q.push({x, y, change_left(f + 'A') - 'A', s + 1});
        }
    }
    if (ans == 1e17) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}



