/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 10 Apr 2023 07:39:17 PM CST
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
    return res % p;
}
int inv(int x) {
    return mypow(x, p - 2) % p;
}
signed main () {
    int n; cin >> n;
    vector<int> arr(n);
    int LCM = 1;
    for (auto &a : arr) {
        cin >> a;
        LCM = lcm(a, LCM) ;
    }
    int ans = 0;
    for (auto a : arr) {
        cout << inv(a) * LCM << "\n";
        ans = (ans + LCM / a) % p;
    }
    cout << ans % p << "\n";
    return 0;
}
