/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 18 Apr 2023 09:17:05 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    vector<array<int, 3>> msg(n);
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        msg[i] = {x, y, z};
    }
    int INF = 1e9;
    auto dis = [&](int x, int y) { 
        return abs(msg[x][0] - msg[y][0]) + abs(msg[x][1] - msg[y][1]) + max(msg[y][2] - msg[x][2], 0ll);
    };
    vector<vector<int>> dp((1 << n) + 1, vector<int>(n, INF));
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u != v && !(i & (1 << v))) {
                    dp[i | (1 << v)][v] = min(dp[i | (1 << v)][v], dp[i][u] + dis(v, u)); 
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0];
    return 0;
}
