/*************************************************************************
	> File Name: 1775c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 10 20:55:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        if (n == x) {
            cout << n << "\n";
            continue;
        }
        if (x > n) {
            cout << -1 << "\n";
            continue;
        }
        int ans = 0;
        int i;
        for (i = 63; i > -1; i--) {
            if ((n >> i & 1) != (x >> i & 1)) break;
            if (n >> i & 1) ans += (1ll << i);
        }
        if (x - ans != 0) {
            cout << -1 << "\n";
            continue;
        }
        ans += (1ll << (i + 1));
        if ((ans & n) != x) {
            cout << -1 << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}

