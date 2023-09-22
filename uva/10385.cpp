/*************************************************************************
  > File Name: 10385.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Mon Sep 18 17:02:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    double s;
    while (cin >> s) {
        int n; cin >> n;
        using P = pair<double, double>;
        vector<P> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        double left = 0.0, right = s;
        const double eps = 1e-9;
        auto check = [&](double mid) -> double {
            double mine = mid / a[n].first + (s - mid) / a[n].second;
            double mx = 1e9;
            for (int i = 1; i < n; i++) {
                double your = mid / a[i].first + (s - mid) / a[i].second;
                mx = min(mx, your);
            }
            return mx - mine;
        };
        for (int i = 1; i <= 200; i++) {
            double leftmid = left + (right - left) / 3.0;
            double rightmid = right - (right - left) / 3.0;
            if (check(leftmid) > check(rightmid)) right = rightmid; 
            else left = leftmid;
        }
        left = (left + right) / 2.0;
        double t = check(left);
        cout << setprecision(2) << fixed;
        if (not (t < 0 and abs(t) > 1e-10)) { 
            cout << "The cheater can win by " << int(t * 3600 + 0.5) << " seconds with r = " << left << "km and k = " << s - left << "km.\n";
        }
        else {
            cout << "The cheater cannot win.\n";
        }
    }
    return 0;
}

