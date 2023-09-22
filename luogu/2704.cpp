/*************************************************************************
	> File Name: 2704.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 18:10:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[105][1025][1025];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'H') g[i] += (1 << (m - j - 1));
        }
    }
    vector<int> avl[(1 << m) + 1];
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (!(i & j)) avl[i].push_back(j);
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        for (auto now = 0; now < (1 << m); now++) {
            if ((now & g[i]) or (now & (now << 1)) or (now & (now << 2))) continue;
            for (auto last : avl[now]) {
                if (last & g[i - 1]) continue;
                for (auto pre : avl[last]) {
                    if (pre & now) continue;
                    dp[i % 2][now][last] = max(dp[i % 2][now][last], dp[(i - 1 + 2) % 2][last][pre] + __builtin_popcount(now));
                }
            }
        }
    }
    cout << dp[(n + 2) % 2][0][0] << "\n";
    return 0;
}

