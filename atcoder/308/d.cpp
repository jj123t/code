/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  1 20:18:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string t = "snuke";
    map<char, char> nxt;
    for (int i = 0; i < 5; i++) {
        nxt[t[i]] = t[((i - 1) + 5) % 5];
    }
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    using P = pair<int, int>;
    using PP = pair<P, char>;
    vector<vector<bool>> used(n + 1, vector<bool>(m + 1, false));
    queue<PP> q; q.push(make_pair(P(0, 0), s[0][0]));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
        auto [a, r] = q.front(); q.pop();
        auto [x, y] = a;
        if (P(x, y) == P(n - 1, m - 1)) {
            cout << "Yes\n";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            //.cout << s[tx][ty] << " " << r << "\n";
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || nxt[s[tx][ty]] != r || used[tx][ty]) {
                continue;
            }
            used[tx][ty] = true;
            q.push(make_pair(P(tx, ty), s[tx][ty]));
        }
    }
    cout << "No\n";
    return 0;
}

