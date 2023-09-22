/*************************************************************************
	> File Name: 1074.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep  2 09:35:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n = 9;
int row[10][10], col[10][10], dir[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int grid[10][10];
int point(int x, int y) {
    if (x == 1 or y == 1 or x == 9 or y == 9) return 6;
    if (x == 2 or y == 2 or x == 8 or y == 8) return 7;
    if (x == 3 or y == 3 or x == 7 or y == 7) return 8;
    if (x == 4 or y == 4 or x == 6 or y == 6) return 9;
    return 10;
}
int ans = 0;
bool check(int x, int y) {
    if (x <= 0 or x > n or y <= 0 or y > n) return false;
    return true;
}
bool vis[10][10];
void dfs(int x, int y, int s) {
    ans = max(ans, s);
    cout << s << '\n';
    if (grid[x][y]) {
        for (int i = 0; i < 4; i++) {
            if (!check(x + dx[i], y + dy[i])) continue;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            int j = grid[x][y];
            row[x][j] = col[x + y][j] = dir[n + x - y][j] = true;
            dfs(x + dx[i], y + dy[i], s + grid[x][y] * point(x, y));
            row[x][j] = col[x + y][j] = dir[n + x - y][j] = false;
            vis[x][y] = false;
        }
    }
    else {
        for (int j = 1; j <= 9; j++) {
            if (!row[x][j] and !col[x + y][j] and !dir[n + x - y][j]) {
                if (vis[x][y]) continue;
                vis[x][y] = true;
                row[x][j] = col[x + y][j] = dir[n + x - y][j] = true;
                grid[x][y] = j;
                for (int i = 0; i < 4; i++) { 
                    if (!check(x + dx[i], y + dy[i])) continue;
                    dfs(x + dx[i], y + dy[i], s + grid[x][y] * (point(x, y)));
                }
                row[x][j] = col[x + y][j] = dir[n + x - y][j] = false;
                grid[x][y] = 0;
                vis[x][y] = false;
            }
        }
    }
}
int main()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    dfs(1, 1, 0);
    cout << ans << "\n";
    return 0;
}

