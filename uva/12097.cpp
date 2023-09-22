/*************************************************************************
	> File Name: 12097.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 09:08:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const double pi = 4.0 * atan(1);
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, f; cin >> n >> f; f++;
        vector<double> pie(n + 1);
        for (int i = 1; i <= n; i++) { cin >> pie[i]; pie[i] = pi * pie[i] * pie[i]; }
        double left = 0, right = 1e9;
        auto check = [&](double mid) -> bool {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                cnt += int(pie[i] / mid);
            }
            return cnt >= f;
        };
        const double eps = 1e-9;
        for (int i = 1; i <= 100; i++) {
            double mid = (left + right) / 2.0;
            if (check(mid)) left = mid + eps;
            else right = mid - eps;
        }
        cout << setprecision(4) << fixed << left << "\n";
    }
    return 0;
}

