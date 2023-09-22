/*************************************************************************
	> File Name: 1516.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 13:40:24 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int extgcd(int &x, int &y, int a, int b) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
signed main()
{
    int x, y, m, n, l; cin >> x >> y >> m >> n >> l;
    int a = x - y, b = n - m;
    if (b < 0) b = -b, a = -a;
    int x0, y0;
    int d = extgcd(x0, y0, b, l);
    if (a % d != 0) {
        cout << "Impossible";
    }
    else {
        int t = l / d;
        cout << ((x0 * a / d) % t + t ) % t;
    }
    return 0;
}

