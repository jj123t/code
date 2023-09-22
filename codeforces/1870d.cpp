/*************************************************************************
	> File Name: 1870d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 23:16:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int k; cin >> k;
        int mi = 1e9 + 1, idx = 0;
        for (int i = 1; i <= n; i++) {
            if (mi >= a[i]) {
                mi = a[i];
                idx = i;
            }
        }
        vector<int> ans(n + 2);

        for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}



