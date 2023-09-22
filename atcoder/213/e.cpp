/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May  8 01:18:45 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto &c : s) cin >> c;
    using P = pair<int, int>;
    using PP = pair<int, P>;
    priority_queue<PP, vector<PP>, greater<PP>> q; q.push(make_pair(0, P(0, 0)));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dxx[20] = {2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2};
    int dyy[20] = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};
    auto check = [&] (int x, int y) -> bool  {
        return !(x < 0 || x >= n || y < 0 || y >= m);
    };
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    while (!q.empty()) {
        auto [t, res] = q.top(); q.pop();
        auto [x, y] = res;
        if (vis[x][y]) continue;
        vis[x][y] = true;
        if (P(x, y) == P(n - 1, m - 1)) {
            cout << t ;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (check(tx, ty) && s[tx][ty] == '.') {
                q.push(make_pair(t, P(tx, ty)));
            }
        }
        for (int i = 0; i < 20; i++) {
            int tx = dxx[i] + x;
            int ty = dyy[i] + y;
            if (check(tx, ty)) {
                q.push(make_pair(t + 1, P(tx, ty)));
            }
        }
    }
    return 0;
}
