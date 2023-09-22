/*************************************************************************
	> File Name: 1753.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 12:45:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; double t;
    while (cin >> n >> t) {
        using P = pair<int, int>;
        vector<P> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        auto check = [&](double mid) -> double {
            double tmp = 0;
            for (int i = 1; i <= n; i++) {
                tmp += a[i].first / (a[i].second + mid);
            }
            return tmp;
        };
        const double eps = 1e-9;
        double left = -1e7, right = 1e7;
        for (int i = 1; i <= n; i++) {
            if (a[i].first < 0) left = max(left, -1.0 * a[i].second);
            else left = max(left, -1.0 * a[i].second);
        }
        for (int i = 0; i <= 100; i++) {
            double mid = (left + right) / 2.0;
            if (check(mid) < t) right = mid - eps; 
            else left = mid + eps;
        }
        cout << setprecision(25) << fixed ;
        cout << left << "\n";
    }
    return 0;
}

