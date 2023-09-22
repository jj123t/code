/*************************************************************************
	> File Name: 5104.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 15:34:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 7;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x) {
    return mypow(x, p - 2);
}
signed main()
{
    int w, n, k; cin >> w >> n >> k;
    int ans = w * inv(mypow(2, k)) % p;
    cout << ans << "\n";
    return 0;
}

