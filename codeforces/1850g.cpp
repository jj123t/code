/*************************************************************************
	> File Name: 1850g.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 23:56:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    using db = long double;
    using P = pair<int, int>;
    const double pi = 4.0 * atan(1.0);
    int tt; cin >> tt;
    while (tt--) {
        int n ;cin >> n;
        vector<P> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
        map<int, int> mp[8];
        for (int i = 1; i <= n; i++) {
            auto [x, y] = arr[i];
            mp[0][x]++;
            mp[1][y]++;
            mp[2][y - x]++;
            mp[3][y + x]++;
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (auto [x, y] : mp[i]) {
                ans += y * (y - 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

