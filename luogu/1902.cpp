/*************************************************************************
	> File Name: 1902.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 18 22:21:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, int> ;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    auto bfs = [&](int mid) {
        queue<P> q; 
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) q.push(P(0, i)), vis[0][i] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1) return true;
            for (int i = 0; i < 4; i++) {
                int rx = x + dx[i];
                int ry = y + dy[i];
                if (rx < 0 || rx >= n || ry < 0 || ry >= m || g[rx][ry] > mid || vis[rx][ry]) continue;
                vis[rx][ry] = true;
                q.push(P(rx, ry));
            }
        }
        return false;
    };
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = left + right >> 1;
        if (bfs(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << left << '\n';
    return 0;
}

