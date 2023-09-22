/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 18:25:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define db double
int main()
{
    using P = pair<db, db>;
    db t = 0.0;
    int n; cin >> n;
    vector<P> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    for (int i = 0; i < n; i++) {
        t += a[i].first / a[i].second;
    }
    t /= 2.0;
    db t2 = 0.0, s = 0.0;
    for (int i = 0; i < n; i++) {
        if (t2 + a[i].first / a[i].second > t) {
            s += (t - t2) * a[i].second;
            break;
        }
        else {
            t2 += a[i].first / a[i].second;
            s += a[i].first;
        }
    }
    cout << setprecision(20) << fixed << s << "\n";
    return 0;
}

