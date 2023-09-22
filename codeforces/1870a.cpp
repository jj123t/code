/*************************************************************************
	> File Name: 1870a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 22:30:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k, x; cin >> n >> k >> x;
        int ans = 0;
        if (k <= n and k - 1 <= x) {
            int a = (0 + k - 1) * (k) / 2;
            int d = x;
            if (x == k) d--; 
            ans = a + d * (n - k);
        }
        else {
            cout << -1 << "\n";
            continue;
        }
        cout << ans << "\n";
    }
    return 0;
}

