/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 18:47:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    auto check = [&](ll x, ll y, ll a, ll b) {
        if (x <= 0 || y <= 0) return false;
        return ((a / y + (a % y != 0) + b / y + (b % y != 0)) <= x || (a / x + (a % x != 0) + b / x + (b % x != 0)) <= y);
    };
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    bool flag = false;
    flag |= check(x - a / y - (a % y != 0), y, b, c);
    flag |= check(x - b / y - (b % y != 0), y, a, c);
    flag |= check(x - c / y - (c % y != 0), y, b, a);

    flag |= check(x, y - a / x - (a % x != 0), b, c);
    flag |= check(x, y - b / x - (b % x != 0), a, c);
    flag |= check(x, y - c / x - (c % x != 0), b, a);
    
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}

