/*************************************************************************
	> File Name: 1848a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 16 22:06:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        int x, y; cin >> x >> y;
        using P = pair<int, int>;
        int mp[110][110];
        memset(mp,sizeof(mp), 0);
        vector<pair<int, int>> arr(k);
        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            arr[i] = {a, b};
            mp[a][b]++;
        }
        if (n == 1 or m == 1) {
            if (k >= 2) {
                cout << "NO\n";
            }
            else {
                int d = abs(x - arr[0].first) + abs(y - arr[0].second);
                if (d == 2) cout << "NO\n";
                else cout << "YES\n";
            }
            continue;
        }
        if (k >= 3) {
            cout << "NO\n";
        }
        else {
            x--, y--;
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
            using P = pair<int, int>;
            queue<P> q;
            for (int i = 0; i < 4; i++) {
                int rx = x + dx[i];
                int ry = y + dy[i];
                q.push({rx, ry});
            }
            bool ok = false;
            auto check = [&](int a, int b) {
                if (a < 0 || a >= n || b < 0 || b >= m) return false;
                return true;
            };
            int t, r;
            while (!q.empty()) {
                auto [a, b] = q.front(); q.pop();
                if (!check(a, b)) continue;
                bool flag = false;
                for (int i = 0; i < 4; i++) {
                    t = a + dx[i];
                    r = b + dy[i];
                    if (!check(t, r)) continue;
                    if (mp[t + 1][r + 1]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) mp[t][r]--;
                else {
                    ok = true;
                }
            }
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

