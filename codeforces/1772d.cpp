/*************************************************************************
	> File Name: 1772d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 11:57:14 2023
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
        for (int i = 0; i < n; i++) cin >> arr[i];
        int l = 0, r = 1e10;
        for (int i = 1; i < n; i++) {
            int a = arr[i - 1];
            int b = arr[i];
            int L, R;
            if (a == b) continue;
            else if (a > b) {
                L = (a + b + 1) / 2, R = 1e9;
            }
            else {
                L = 0, R = (a + b) / 2;
            }
            l = max(l, L);
            r = min(r, R);
        }
        if (l > r) cout << -1 << "\n";
        else cout << l << "\n";
    }
    return 0;
}

