/*************************************************************************
	> File Name: 4942.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 08:57:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int tt; cin >> tt;
    int p = 9;
    while (tt--) {
        int l, r; cin >> l >> r;
        int d = (r - l + 1) % p;
        int ans = ((((l + r) % p) * 5 % p) * d % p) % p;
        cout << ans << "\n";
    }
    return 0;
}

