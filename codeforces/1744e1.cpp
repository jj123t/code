/*************************************************************************
	> File Name: 1744e1.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 02:52:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
    signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int ans1 = -1, ans2 = -1;
        for (int i = a + 1; i <= c; i++) {
            int x =  a * b / gcd(a * b, i);
            if (d / x - b / x >= 1) {
                ans1 = i, ans2 = (d / x) * x;
                break;
            }
        }
        // x * y = k * a * b;
        // x | gcd(a * b, y);
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}

