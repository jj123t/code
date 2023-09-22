/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 10 Apr 2023 07:10:20 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
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
const int N = 1e5 + 100;
vector<int> fac(N, 1), invfac(N , 1);
void init()  {
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    for (int i = 1; i < N; i++) {
        invfac[i] = invfac[i - 1] * inv(i) % p;
    }
}
int C(int a, int b) {
    if (a < b) return 0;
    return  (fac[a] * invfac[b] % p) * invfac[a - b] % p;
}
signed main () {
    init();
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0);
    for (auto &a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    int mx = 0, mi = 0;
    for (int i = 0; i < n; i++) {
        mx += C(i, k - 1) * arr[i] % p;
        mx %= p;
        mi += C(n - 1 - i, k - 1) * arr[i] % p;
        mi %= p;
    }
    cout << ((mx-mi + p) % p) << "\n";
    return 0;
}
