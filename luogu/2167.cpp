/*************************************************************************
	> File Name: 2167.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 15:06:45 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        const int p = 1000003;
        vector<string> s(n + 1); 
        for (int i = 0; i < n; i++) cin >> s[i];
        vector<vector<int>> mp(s[0].size() + 1, vector<int>(27, 0));
        vector<vector<int>> dp(s[0].size() + 1, vector<int>((1 << n) + 1, 0));
        for (int len = 0; len < s[0].size(); len++) { 
            for (int c = 0; c < 26; c++) {
                for (int i = 0; i < n; i++) {
                    if (s[i][len] == '?' or s[i][len] == char(c + 'a')) {
                        mp[len][c] |= (1 << i);
                    }
                }
            }
        }
        dp[0][(1 << n) - 1] = 1;
        for (int len = 0; len < s[0].size(); len++) {
            for (int i = 0; i < (1 << n); i++) {
                if (dp[len][i]) {
                    for (int c = 0; c < 26; c++) {
                        dp[len + 1][i & (mp[len][c])] += dp[len][i];
                        dp[len + 1][i & (mp[len][c])] %= p;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    res++;
                }
            }
            if (res == k) {
                ans += dp[s[0].size()][i];
                ans %= p;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

