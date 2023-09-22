/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 10 05:06:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
const int N = 1e6 + 10;
const int p = 998244353;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return (res + p) % p;
}
signed main()
{
    int n; cin >> n;
    int d; cin >> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) continue;
        int y = mypow(2, i) % p;  
        int x = 0;
        if (i + d < n) x = mypow(2, d) % p; 
        int r = n - 1 - i;
        r = min(r, d - 1);
        if (1 <= r) {
            int l = d - r;
            if (l <= r) {
                x += (mypow(2, d - 2) % p * (r - l + 1) % p) % p;
                x %= p;
            }
        }
        ans += (x % p * y % p) % p;
        ans %= p;
    }
    ans = (ans % p * 2) % p;
    cout << ans;
    return 0;
}

