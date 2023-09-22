/*************************************************************************
	> File Name: 1748c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:00:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> pfx(n + 1, 0);
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        for (int i = 1; i <= n; i++) pfx[i] = pfx[i - 1] + arr[i - 1];
        map<int, int> mp;
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            mp[pfx[i]]++;
            if (arr[i - 1] == 0) {
                int mx = 0;
                for (auto x : mp) {
                    mx = max(x.second, mx);
                }
                ans += mx;
                mp.clear();
            }
        }
        ans += mp[0];
        cout << ans << "\n";
    }
    return 0;
}

