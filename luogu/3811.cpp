/*************************************************************************
	> File Name: 3811.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 03:04:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int extgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int my_pow(int a, int b, int p) {
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, p; cin >> n >> p;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cout << (my_pow(i, p - 2, p)) << "\n";
    }
    return 0;
}

