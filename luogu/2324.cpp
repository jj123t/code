/*************************************************************************
  > File Name: 2324.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Sep  2 11:08:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
int dy[8] = {2, -2, 2, -2, 1, 1, -1, -1};
map<vector<string>, int> mp;
int n = 5;
vector<string> grid(5);
bool check(int x, int y) {
    if (0 > x or x >= n or 0 > y or y >= n) return false;
    return true;
}
void bfs(vector<string> startt, vector<string> endt, int lim) {
    queue<vector<string>> q; q.push(startt);
    mp[grid] = 0;
    vector<string> tar = endt;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        auto c = t;
        if (mp[t] == lim) break;
        auto cp = t;
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (t[i][j] == '*') {
                    x = i, y = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!check(nx, ny)) continue;
            swap(t[nx][ny], t[x][y]);
            if (!mp[t]) {
                mp[t] = mp[c] + 1;
                q.push(t);
            } 
            swap(t[nx][ny], t[x][y]);
        }
    }
}
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        for (int i = 0; i < n; i++) cin >> grid[i];
        vector<string> tar;
        tar.push_back("11111");
        tar.push_back("01111");
        tar.push_back("00*11");
        tar.push_back("00001");
        tar.push_back("00000");
        if (tar == grid) {
            cout << 0 << '\n';
            continue;
        }
        bfs(grid, tar, 9);
        auto A = mp;
        mp.clear();
        bfs(tar, grid, 8);
        auto B = mp;
        mp.clear();
        int ans = 1e9;
        for (auto [x, y] : A) if (tar == x and y) ans = min(ans, y);
        for (auto [x, y] : B) if (grid == x and y) ans = min(ans, y);
        for (auto [x, y] : A) {
            if (y <= 8) {
                if (B[x] and B[x] <= 7) {
                    ans = min(ans, y + B[x]);
                }
            }
        }
        if (ans == 1e9) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}

