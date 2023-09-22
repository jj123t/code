/*************************************************************************
	> File Name: 1176.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 21:19:45 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[400100];
signed main()
{
    int n, W; cin >> n >> W;
    vector<array<int, 3>> c;
    for (int i = 1; i <= n; i++) {
        int a, b, x; cin >> a >> b >> x;
        for (int j = 1; j <= x; j *= 2) {
            c.push_back({j * a, j * b});
            x -= j;
        }
        if (x) c.push_back({x * a, x * b});
    }
    for (int i = 0; i <= c.size(); i++) {
        for (int j = W; j >= c[i][1]; j--) {
            dp[j] = max(dp[j], dp[j - c[i][1]] + c[i][0]);
        }
    }
    cout << dp[W];
    return 0;
}

