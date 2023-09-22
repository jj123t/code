/*************************************************************************
	> File Name: 4301.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 16:24:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<int> t(50);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 30; j >= 0; j--) {
            if (a[i] >> j & 1) {
                if (!t[j]) { t[j] = a[i]; break; }
                else a[i] ^= t[j];
            }
        }
        if (!a[i]) ans += x;
    }
    cout << ans << "\n";
    return 0;
}

