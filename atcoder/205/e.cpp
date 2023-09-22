/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May  3 15:51:01 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int p = 1e9 + 7;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return (res + p) % p;
} 
int inv(int x) {
    return mypow(x, p - 2) % p;
}
int C(int a, int b) {
    if (a < 0 || b < 0 || b > a) return 0;
    int res = 1;
    for (int i = 1; i <= a; i++) res = (res % p * i % p) % p;
    for (int i = 1; i <= b; i++) res = (res % p * inv(i) % p) % p;
    for (int i = 1; i <= a - b; i++) res = (res % p * inv(i) % p) % p;
    return res % p;
}
signed main () {
    int n, m, k; cin >> n >> m >> k;
    if (m + k < n) {
        cout << 0;
        return 0;
    }
    int x = C(n + m, n) % p;
    int y = C(n + m, n - k - 1) % p;
    cout << (x - y + p) % p;
    return 0;
}

