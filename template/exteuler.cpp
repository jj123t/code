/*************************************************************************
	> File Name: exteuler.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 12:35:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) res = res / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}
int mypow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
signed main()
{
    int a, m; string b; cin >> a >> m >> b;
    int p = phi(m);
    int res = 0;
    bool flag = false;
    for (auto c : b) {
        res = (res * 10 + (c - '0'));
        if (res >= p) res %= p, flag = true;
    }
    if (flag) res += p;
    int ans = mypow(a, res, m);
    cout << ans ;
    return 0;
}


