/*************************************************************************
	> File Name: 1777b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 13:40:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 7;
signed main()
{
    int tt; cin >> tt;
    vector<int> fac(101000, 1), invfac(101000, 1);
    for (int i = 1; i < 100100; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    while (tt--) {
        int n; cin >> n;
        cout << (n * (n - 1) % p) * fac[n] % p << "\n";
    }
    return 0;
}

