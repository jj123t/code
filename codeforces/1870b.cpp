/*************************************************************************
	> File Name: 1870b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 22:30:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        int ans1 = 0;
        for (int i = 1; i <= n; i++) ans1 ^= a[i];

        int ans2 = 0;
        int tmp = 0;
        for (int i = 1; i <= m; i++) tmp |= b[i];
        for (int i = 1; i <= n; i++) a[i] |= tmp;
        for (int i = 1; i <= n; i++) ans2 ^= a[i];

        if (n & 1) cout << ans1 << " " << ans2 << "\n";
        else cout << ans2 << " " << ans1 << "\n";
    }
    return 0;
}

