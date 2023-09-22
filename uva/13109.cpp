/*************************************************************************
	> File Name: 13109.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 21:02:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, w; cin >> n >> w;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end());
        int s = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s + a[i] <= w) {
                s += a[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

