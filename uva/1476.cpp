/*************************************************************************
	> File Name: 1476.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 13:27:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<double> a(n + 1), b(n + 1), c(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        double left = 0.0, right = 1e3;
        auto check = [&](double mid) -> double {
            double res = -1e9;
            for (int i = 1; i <= n; i++) {
                res = max(res, a[i] * mid * mid + b[i] * mid + c[i]);
            }
            return res;
        };
        const double eps = 1e-9;
        for (int i = 0; i < 100; i++) {
            double leftmid = left + (right - left) / 3.0;
            double rightmid = right - (right - left) / 3.0;
            if (check(leftmid) <= check(rightmid)) right = rightmid - eps;
            else left = leftmid + eps;
        }
        cout << setprecision(4) << fixed;
        cout << left << "\n";
    }
    return 0;
}

