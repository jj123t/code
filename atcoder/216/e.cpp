/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May  8 23:46:31 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int, int>;
const int N = 10;
int x, y; 
int ans = 0;
P s;
vector<vector<int>> e;
int k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(set<P> st) {
    queue<P> q; q.push(s);
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    auto g = [&](int x, int y) {
        return !st.count(P(x, y));
    };
    int tmp = 1;
    while (!q.empty()) {
        auto res = q.front(); q.pop();
        if (vis[res.first][res.second]) continue;
        vis[res.first][res.second] = true;
        for (int i = 0; i < 4; i++) {
            int tx = res.first + dx[i];
            int ty = res.second + dy[i];
            if (g(tx, ty)) {
                q.push(P(tx, ty));
                if (e[tx][ty] == 1) tmp++;
            }
        }
    }
    if (tmp == k) return true;
    return false;
}
void dfs(int rx, int ry, set<P> vis) {
    if (rx == x && ry == y) {
        if (check(vis)) {
            ans.insert(vis);
        }
        return;
    }
    if (vis.count(P(rx, ry))) {
        return ;
    }
    vis.insert(P(tx, ty));
    auto f = [&](int x, y) {
        return !(x < 0 || x >= 9 || y < 0 || y >= 9 || e[x][y] == 1);
    };
    for (int i = 0; i < 4; i++) {
        int tx = rx + dx[i];
        int ty = ry + dy[i];
        if (f(tx, ty)) {
            vis.insert(P(tx, ty));
            dfs(tx, ty, vis);
            vis.erase(P(tx, ty));
        }
    }
}
int main () {
    vector<int> res(9, 0);
    vector<int> rest;
    for (int i = 0; i < 4; i++) {
        e.push_back(res);
        e.push_back(rest);
        for (int j = 0; j < 4; j++) {
            int x; cin >> x;
            e.back().push_back(0);
            e.back().push_back(x);
        }
        e.back().push_back(0);
    }
    e.push_back(res);
    for (int i = 0; i < 9; i++) { 
        for (int j = 0; j < 9; j++) {
            if (e[i][j] == 1) {
                s = P(i, j);
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            dfs(i, j, {});
        }
    }
    cout << ans.size();
    return 0;
}
