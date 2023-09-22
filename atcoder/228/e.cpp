/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 23:04:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 998244353;
int mypow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
signed main()
{
    int n; cin >> n;
    int m, k; cin >> m >> k;
    if (k % p == 0) {
        cout << 0;
        return 0;
    }
    int a = mypow((m % (p - 1)), n, p - 1);
    int b = mypow(k % (p), a, p);
    cout << b << "\n";
    return 0;
}

