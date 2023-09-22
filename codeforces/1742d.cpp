/*************************************************************************
	> File Name: 1742d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 04:02:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x] = i + 1;
        }
        int ans = -1;
        for (auto x : mp) {
            for (auto y : mp) {
                if (gcd(x.first, y.first) == 1) {
                    ans = max(ans, x.second + y.second);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

