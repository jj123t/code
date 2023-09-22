/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 04:17:31 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0)  {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int inv(int a, int p) {
    int x, y;
    if (gcd(a, p) != 1) return -1; 
    int d = extgcd(a, p, x, y);
    return (x + p) % p;
}
signed main () {
    int tt; cin >> tt;
    while (tt--) {
        int n, s, k; cin >> n >> s >> k;
        int GCD = gcd(n, gcd(s, k));
        n /= GCD, s /= GCD, k /= GCD;
        int a = inv(k, n);
        if (a == -1) {
            cout << -1 << '\n';
            continue;
        }
        int b = (-s + n) % n;
        int ans = (a * b + n) % n;
        cout << ans << '\n';
    }
    return 0;
}
