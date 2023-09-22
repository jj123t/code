/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 20 Apr 2023 04:37:32 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));  
    using P = pair<int, int>;
    map<char, vector<P>> mp;
    P start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') start = P(i, j);
            if (s[i][j] == 'G') end = P(i, j);
            if (s[i][j] == '.' || s[i][j] == '#') continue;
            mp[s[i][j]].push_back(P(i, j));
        }
    }
    using PP = pair<P, int>;
    queue<PP> q; q.push(make_pair(start, 0));
    auto check = [&](int x, int y) {
        return !(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#');
    };
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[start.first][start.second] = true;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<bool> used(100, false);
    while (!q.empty()) {
        auto tmp = q.front(); q.pop();
        auto loc = tmp.first; 
        if (loc == end) {
            cout << tmp.second;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            auto [tx, ty] = P(loc.first + dx[i], loc.second + dy[i]);
            if (check(tx, ty) && !vis[tx][ty]) {
                vis[tx][ty] = true;
                q.push(PP(P(tx, ty), tmp.second + 1));
            }
        }
        if (s[loc.first][loc.second] != '.') { 
            if (used[s[loc.first][loc.second]]) continue;
            used[s[loc.first][loc.second]] = true;
            for (auto [a, b] : mp[s[loc.first][loc.second]]) {
                if (check(a, b) && !vis[a][b]) {
                    vis[a][b] = true;
                    q.push(PP(P(a, b), tmp.second + 1));
                }
            }
        }
    }
    cout << -1;
    return 0;
}
