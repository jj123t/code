/*************************************************************************
	> File Name: 4981.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 10:29:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 9;
int mypow(int a, int b) {
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
    int tt; cin>> tt;
    while (tt--) {
        int n; cin >> n;
        cout << mypow(n, n - 1) << "\n";
    }
    return 0;
}

