/*************************************************************************
	> File Name: 3572.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Aug  6 16:50:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) cin >> d[i];
    int q; cin >> q;
    vector<int> rk(q + 1);
    for (int i = 1; i <= q; i++) cin >> rk[i];
    for (int r = 1; r <= q; r++) {
        int k = rk[r];
        deque<array<int, 3>> q; q.push_back({1, 0, d[1]});
        for (int i = 2; i <= n; i++) {
            while (!q.empty() and q.front()[0] < i - k) q.pop_front();
            auto [id, cost, h] = q.front();
            int res = 0;
            if (h <= d[i]) {
                res = cost + 1;
            }
            else {
                res = cost;
            }
            while (!q.empty() and ((q.back()[1] > res) or (q.back()[1] == res and q.back()[2] <= d[i]))) {
                q.pop_back();
            }
            q.push_back({i, res, d[i]});
        }
        int ans = 1e9;
        while (!q.empty()) {
            if (q.front()[0] == n) ans = min(ans, q.front()[1]);
            q.pop_front();
        }
        cout << ans << "\n";
    }
    return 0;
}

