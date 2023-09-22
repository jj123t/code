/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 04:42:03 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int p = 998244353;
#define int long long 
signed main()
{
    int h, w, k; cin >> h >> w >> k;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(2, vector<int>(2, 0))); 
    bool flag1 = (x1 == x2);
    bool flag2 = (y1 == y2);
    dp[0][flag1][flag2] = 1;
    for (int i = 1; i <= k; i++) {
        int &a = dp[i][0][0]; a %= p;
        a += (dp[i - 1][0][0] * ((h - 2) % p)) % p ; a %= p;
        a += (dp[i - 1][0][0] * ((w - 2) % p)) % p ; a %= p;
        a += (dp[i - 1][0][1] * ((w - 1) % p)) % p ; a %= p;
        a += (dp[i - 1][1][0] * ((h - 1) % p)) % p; a %= p;
 
        int &b = dp[i][0][1]; b %= p;
        b += dp[i - 1][0][0] % p; b %= p;
        b += (dp[i - 1][1][1] * ((h - 1) % p)) % p; b %= p;
        b += (dp[i - 1][0][1] * ((h - 2) % p)) % p; b %= p;

        int &c = dp[i][1][0]; c %= p;
        c += dp[i - 1][0][0] % p ; c %= p;
        c += (dp[i - 1][1][1] * ((w - 1) % p)) % p; c %= p;
        c += (dp[i - 1][1][0] * ((w - 2) % p)) % p; c %= p;
  
        int &d = dp[i][1][1];  d %= p;
        d += dp[i - 1][1][0] % p; d %= p;
        d += dp[i - 1][0][1] % p; d %= p;

    }
    cout << dp[k][1][1] % p;
    return 0;
}

