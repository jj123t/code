/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun  1 04:40:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n, k, d; cin >> n >> k >> d;
    /*
    n - ad + bd = x;
    n - ad + (k - a) * d = x;
    n - ad + kd - a * d = x;
    n + kd - 2a * d = x;
    n + (k - 2 * a) * d = x;
    k - 2 * a > n / d
    k - 2 * a < n / d;
    */
    n = abs(n);
    int r = min(k, n / d);
    int a = (r + k) / 2;
    int b = (r + k) / 2 + 1;
    auto f = [&](int x) {
        return abs((k - 2 * x) * d + n);
    };
    cout << min({f(a), f(b)});
    return 0;
}


