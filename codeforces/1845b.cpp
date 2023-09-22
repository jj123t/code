/*************************************************************************
	> File Name: 1845b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 22:09:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        using P = pair<int, int> ;
        P a; cin >> a.first >> a.second;
        P b; cin >> b.first >> b.second;
        P c; cin >> c.first >> c.second;
        swap(a, c);
        int d1 = abs(a.first - b.first) + abs(a.second - b.second);
        auto [x1, y1] = a;
        auto [x2, y2] = b;
        auto [x3, y3] = c;

        bool flag1 = (min(x1, x2) <= x3 && x3 <= max(x1, x2)) ;
        bool flag2 = (min(y1, y2) <= y3 && y3 <= max(y1, y2)) ;
        if (flag1 && flag2) {
            cout << 1 << "\n";
        }
        else if (flag1) {
            cout <<  min(abs(y3 - y1), abs(y3 - y2)) + 1 << "\n";
        }
        else if (flag2) {
            cout <<  min(abs(x3 - x1), abs(x3 - x2)) + 1 << "\n";
        }
        else {
            cout <<  min(abs(y3 - y1), abs(y3 - y2)) + min(abs(x3 - x1), abs(x3 - x2)) + 1 << "\n";
        }
    }
    return 0;
}

