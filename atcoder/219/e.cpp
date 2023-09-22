/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 10 01:50:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
using P = pair<int, int>;

vector<vector<int>> gph; 
set<vector<vector<int>>> stans;
set<P> st;
P s;
int ans = 0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool dis(int x, int y) {
    return (x <= 0 || x >= 10 || y <= 0 || y >= 10);
}
bool check(int x, int y, vector<vector<int>> vis) {
    int cur = 0;
    bool flag = false;
    queue<P> q; q.push(P(x, y));
    vector<vector<bool>> used(11, vector<bool>(11, false));
    used[x][y] = true;
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        if (gph[a][b] == 1) cur++;
        for (int i = 0; i < 4; i++) {
            int rx = dx[i] + a;
            int ry = dy[i] + b;
            if (dis(rx, ry)) return false;
            if (vis[rx][ry] == 1) continue;
            if (used[rx][ry]) continue;
            used[rx][ry] = true;
            q.push(P(rx, ry));
        }
    }
    if (cur == st.size()) return true;
    return false;
}
int fx, fy;
void dfs(int x, int y, vector<vector<int>> vis) {
    if (vis[fx][fy] == 1) {
        //if (check(s.first, s.second, vis)) stans.insert(vis);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int rx = dx[i] + x;
        int ry = dy[i] + y;
        if (dis(rx, ry)) continue;
        if (gph[rx][ry] == 1) continue;
        if (vis[rx][ry]) continue;
        vis[rx][ry] = 1;
        dfs(rx, ry, vis);
        vis[rx][ry] = 2;
    }
}
signed main()
{
    {
        vector<vector<int>> g(4, vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> g[i][j];
            }
        }
        vector<int> res(11, 0);
        gph.push_back(res);
        for (int i = 0; i < 4; i++) {
            gph.push_back(res);
            vector<int> tmp;
            tmp.push_back(0);
            for (int j = 0; j < 4; j++) {
                tmp.push_back(0);
                tmp.push_back(g[i][j]);
            }
            tmp.push_back(0);
            tmp.push_back(0);
            gph.push_back(tmp);
        }
        gph.push_back(res);
        gph.push_back(res);
        for (int i = 0; i < gph.size(); i++) {
            for (int j = 0; j < gph[0].size(); j++) {
                if (gph[i][j] == 1) {
                    st.insert(P(i, j));
                    s = P(i, j);
                }
            }
        }
    }
    cout << st.size() << "\n";
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << gph[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (gph[i][j] != 1) {
                fx = i, fy = j;
                vector<vector<int>> vis(11, vector<int>(11, 0));
                dfs(i, j, vis);
            }
        }
    }
    cout << stans.size();
    return 0;
}

