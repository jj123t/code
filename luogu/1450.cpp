/*************************************************************************
	> File Name: 1450.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 21:37:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c[5], d[5], dp[1000100];
signed main()
{
    for (int i = 1; i <= 4; i++) cin >> c[i];

    dp[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = c[i]; j <= 100000; j++) {
            dp[j] += dp[j - c[i]];
        }
    }
    int tt; cin >> tt;
    while (tt--) {
        for (int j = 1; j <= 4; j++) cin >> d[j];
        int s; cin >> s;
        int ans = dp[s];
        for (int i = 1; i < (1 << 4); i++) {
            int cnt = 0;
            int res = 0;
            for (int j = 0; j < 4; j++) {
                if (i >> j & 1) {
                    cnt++;
                    res += c[j + 1] * (d[j + 1] + 1);
                }
            }
            if (cnt & 1) {
                if (s >= res)
                ans -= dp[s - res];
            }
            else {
                if (s >= res)
                ans += dp[s - res];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

