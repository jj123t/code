/*************************************************************************
	> File Name: 3197.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 19:34:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    int m, n; cin >> m >> n;
    const int p = 1e5 + 3;
    int ans = (mypow(m, n, p) - m * mypow(m - 1, n - 1, p) % p + p) % p;
    cout << ans << "\n";
    return 0;
}

