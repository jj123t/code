/*************************************************************************
	> File Name: 1762c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 18:10:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        s = " " + s;
        int ans = 0;
        int p = 998244353;
        int res = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == s[i - 1]) {
                res = res * 2 % p;
            }
            else {
                res = 1;
            }
            ans = (ans + res) % p;
        }
        cout << ans << "\n";
    }

    return 0;
}

