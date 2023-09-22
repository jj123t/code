/*************************************************************************
	> File Name: 1005.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 18:23:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
__int128 dp[1000][1000];
__int128 arr[1000][1000];
__int128 res[1010];
void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout << char(x % 10 + '0');
}
__int128 pw(__int128 a, __int128 b) {
    __int128 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            arr[i][j] = x;
        }
    }
    for (int k = 1; k <= n; k++) {
        memset(dp, sizeof dp, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = m; j >= i; j--) {
                dp[i][j] = max(dp[i - 1][j] + arr[k][i - 1] * pw(2, (m + i - j - 1)), dp[i][j + 1] + arr[k][j + 1] * pw(2, (m + i - j - 1)));
            }
        }
        for (int i = 1; i <= m; i++) {
            res[k] = max(res[k], dp[i][i] + arr[k][i] * pw(2, m));
        }
    }
    __int128 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += res[i];
    }
    print(ans);
    return 0;
}

