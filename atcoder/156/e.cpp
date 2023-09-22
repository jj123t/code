/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 11 Apr 2023 07:03:45 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 1e6 + 10;
const int p = 1e9 + 7;
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
    return mypow(x, p - 2) % p;
}
vector<int> fac(N, 1), invfac(N, 1); 
void init() {
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    for (int i = 1; i < N; i++) {
        invfac[i] = invfac[i - 1] * inv(i) % p;
    }
}
int C(int a, int b) {
    if (a < b) return 0ll;
    return (fac[a] * invfac[b] % p) * invfac[a - b] % p;
}
signed main () {
    int n, k; cin >> n >> k;
    init();
    int ans = 0;
    for (int i = 0; i < n && i <= k; i++) {
        ans = (ans % p + C(n, i) * C(n - 1, n - i - 1) % p) % p;
    }
    cout << ans % p;
    return 0;
}
