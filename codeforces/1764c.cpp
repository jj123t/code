/*************************************************************************
	> File Name: 1764c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul  2 21:29:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        int tmp = 0;
        int ans = n / 2;
        for (auto [x, y] : mp) {
            tmp += y;
            ans = max(ans, tmp * (n - tmp));
        }
        cout << ans << "\n";
    }
    return 0;
}

