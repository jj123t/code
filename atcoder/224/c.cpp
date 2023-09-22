/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 28 01:57:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                auto [x0, y0] = a[i];
                auto [x1, y1] = a[j];
                auto [x2, y2] = a[k];
                if ((y2 - y1) * (x1 - x0) != (y1 - y0) * (x2 - x1)) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

