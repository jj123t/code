/*************************************************************************
	> File Name: p1024.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May 30 19:38:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
using db = long double;
int main()
{
    db a, b, c, d; cin >> a >> b >> c >> d;
    cout << setprecision(2) << fixed;
    auto f = [&](db x) {
        return (long double)((long double)pow(x, 3) * a + (long double)pow(x, 2) * b + x * c + d); 
    };
    for (int i = -100; i < 100; i++) {
        db left = i;
        db right = i + 1.0;
        db x = f(left);
        db y = f(right);
        if (x == 0) {
            cout << left << " ";
            continue;
        }
        if (x * y < 0) {
            while (right - left >= 0.001) {
                db mid = (right + left) / 2.0;
                if (f(mid) * f(right) <= 0) left = mid;
                else right = mid;
            }
            cout << right << " ";
        }
    }
    return 0;
}

