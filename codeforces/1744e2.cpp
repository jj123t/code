/*************************************************************************
	> File Name: 1744e2.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 03:12:27 2023
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
        set<int> stx, sty; 
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                stx.insert(i);
                stx.insert(a / i);
            }
        }
        for (int i = 1; i * i <= b; i++) {
            if (b % i == 0) {
                sty.insert(i);
                sty.insert(b / i);
            }
        }
        int ans1 = -1, ans2 = -1;
        for (auto x : stx) {
            for (auto y : sty) {
                int t = x * y;
                if ((a / t + 1) * t <= c && (b / (a * b / t) + 1) * (a * b / t) <= d) {
                    ans2 = (b / (a * b / t) + 1) * (a * b / t);
                    ans1 = (a / t + 1) * t;
                } 
            }
        }
        cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}

