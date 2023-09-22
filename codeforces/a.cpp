/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 30 23:23:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> idr(n + 1);
        for (int i = 1; i <= n; i++) idr[arr[i]] = i;
        int st = 1;
        int idx = idr[st];
        int ans = 0;
        st++;
        while (st <= n) {
            while (st <= n and idr[st] > idx) {
                idx = idr[st];
                st++;
            }
            if (st <= n) {
                ans++;
                idx = idr[st];
                st++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

