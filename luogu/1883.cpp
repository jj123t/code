/*************************************************************************
	> File Name: 1883.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 18 19:08:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<array<double, 3>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        const double eps = 1e-11;
        double left = 0, right = 1000.0;
        auto f = [&](double m) {
            double mx = -1e9;
            for (int i = 0; i < n; i++) {
                auto [A, B, C] = a[i];
                mx = max(mx, A * m * m + B * m + C);
            }
            return mx;
        };
        while (left + eps < right) {
            double tl = (right - left) / 3.0 + left;
            double tr = (right - left) / 3.0 * 2.0 + left;
            if (f(tr) >= f(tl)) right = tr;
            else left = tl;
        }
        cout << setprecision(4) << fixed;
        cout << f(left) << "\n";
    }
    return 0;
}

