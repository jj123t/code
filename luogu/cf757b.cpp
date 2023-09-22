/*************************************************************************
	> File Name: cf757b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 15:05:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                while (x % j == 0) x /= j;
                mp[j]++;
            }
        }
        if (x > 1) mp[x]++;
    }
    int ans = 1;
    for (auto [x, y] : mp) ans = max(ans, y);
    cout << ans << "\n";
    return 0;
}

