/*************************************************************************
	> File Name: 3807.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 17:11:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mypow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x, int p) {
    return mypow(x, p - 2, p);
}
int C(int a, int b, int p) {
    if (b > a) return 0;
    if (b > a - b) b = a - b;
    int x = 1, y = 1;
    for (int i = 0; i < b; i++) {
        x = (x * (a - i)) % p;
        y = (y * (i + 1)) % p;
    }
    return x * mypow(y, p - 2, p) % p;
}
int Lucas(int a, int b, int p) {
    if (b == 0) return 1;
    return Lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
}
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, p; cin >> n >> m >> p;
        int ans = Lucas(n + m, n, p);
        cout << ans << "\n";
    }
    return 0;
}

