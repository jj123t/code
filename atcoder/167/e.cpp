/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 13 Apr 2023 10:18:51 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int p = 998244353;
const int N = 2e5 + 10;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}
int inv(int x) {
    return mypow(x, p - 2);
}
vector<int> fac(N, 1), invfac(N, 1);
void  init() {
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    for (int i = 1; i < N; i++) {
        invfac[i] = invfac[i - 1] * inv(i) % p;
    }
}
int C(int a, int b) {
    if (b > a) return 0;
    int x = fac[a] * invfac[b] % p;
    return (x * invfac[a - b] % p); 
}
signed main () {
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;
    init();
    for (int i = 0; i <= k; i++) {
        int x = C(n - 1, i);
        int y = m * mypow(m - 1, n - i - 1) % p;
        ans += x * y % p;
    }
    cout << ans % p;
    return 0;
}
