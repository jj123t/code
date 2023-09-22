/*************************************************************************
	> File Name: 1731b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 10:40:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 7;
int mp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}
signed main()
{
    int tt; cin >> tt;
    int six = mp(6, p - 2);
    int two = mp(2, p - 2);
    while (tt--) {
        int n; cin >> n;
        // 1 * 1 + 2 * 1 + 2 * 2 + 3 * 2 + 3 * 3 ...
        // 1^2 + 2^2 + 3^2 + ... + n^2 + 1 * 2 + 2 * 3 + ... (n) * (n + 1);
        //
        // n * (n + 1) * (2 * n + 1) / 6 + (n - 1) * n * (2 * n - 1) / 6 + (n - 1) * (n) / 2; 
        // 2 -> 1 * 1 + 2 * 1 + 2 * 2;

        int res = ((((n * (n + 1) % p) * (2 * n + 1) % p) * six) % p + (((n - 1) * n % p) * (2 * n - 1) % p) * six % p + ((n - 1) * (n) % p) * two % p) % p; 
        cout << (res * 2022) % p << "\n";
    }
    return 0;
}

