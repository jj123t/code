/*************************************************************************
	> File Name: 1742e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 04:31:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<int> pfx(n + 1, 0);
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pfx[i + 1] = pfx[i] + arr[i];
        }
        vector<int> mx(n + 1, 0);
        for (int i = 0; i < n; i++) {
            mx[i + 1] = max(mx[i], arr[i]);
        }
        while (q--) {
            int x; cin >> x;
            auto it = upper_bound(mx.begin(), mx.end(), x) - mx.begin();
            cout << pfx[it - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}

