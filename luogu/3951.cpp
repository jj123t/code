/*************************************************************************
	> File Name: 3951.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 12:52:31 2023
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
    int a, b; cin >> a >> b;
    // a * x + b * y == 1
    int x, y; int d = extgcd(x, y, a, b);
    while (x >= 0) x -= b, y += a;
    int xt = x + b;
    while (y >= 0) y -= a, x += b;
    int yt = y + a;
    cout << a * (xt - 1) + b * (yt - 1) - 1 << "\n";
    return 0;
}

