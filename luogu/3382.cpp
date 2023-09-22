/*************************************************************************
	> File Name: 3382.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 18 18:20:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    double l, r; 
    cin >> n >> l >> r;
    vector<double> a(n + 1);
    for (int i = 0; i < n + 1; i++) cin >> a[i];
    auto f = [&](double m) {
        double res = a[0];
        for (int i = 1; i < n + 1; i++) {
            res = res * m + a[i];
        } 
        return res;
    };
    const double eps = 1e-6;
    while (l + eps < r) {
        double tl = (r - l) / 3.0 + l;
        double tr = (r - l) / 3.0 * 2.0 + l;
        if (f(tl) >= f(tr)) r = tr;
        else l = tl;
    }
    cout << fixed << setprecision(25);
    cout << l << "\n";
    return 0;
}

