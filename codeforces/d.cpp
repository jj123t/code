/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 31 00:39:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        using P = pair<int, int>;
        queue<P> q;
        q.push({0, 0});
        using PP = pair<P, P>;
        set<PP> st;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        vis[0][0] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            char r = s[x][y];
            for (int i = 0; i < 4; i++) {
                int rx = x + dx[i];
                int ry = y + dy[i];
                if (0 > rx or rx >= n or 0 > ry or ry >= m or vis[rx][ry]) continue;
                vis[rx][ry] = true;
                q.push(P(rx, ry));
                if (s[x][y] == 'R') {
                    if (s[rx][ry] == 'L') {
                        st.insert(make_pair(P(x, y), P(rx, ry)));
                    }
                }
                if (s[x][y] == 'L') {
                    if (s[rx][ry] == 'R') {
                        st.insert(make_pair(P(x, y), P(rx, ry)));
                    }
                }
                if (s[x][y] == 'U') {
                    if (s[rx][ry] == 'D') {
                        st.insert(make_pair(P(x, y), P(rx, ry)));
                    }
                }
                if (s[x][y] == 'D') {
                    if (s[rx][ry] == 'U') {
                        st.insert(make_pair(P(x, y), P(rx, ry)));
                    }
                }
            }
        }
        cout << st.size() << '\n';
        for (auto [A, B] : st) {
            auto [a, b] = A;
            auto [c, d] = B;

        }
    }
    return 0;
}

