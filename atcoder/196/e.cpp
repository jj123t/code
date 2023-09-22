/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 01:10:31 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    int mi = -1e17, mx = 1e17, a = 0;
    for (int i = 0; i < n; i++) {
        int x, t; cin >> x >> t;
        if (t == 1) {
            mi += x;
            mx += x;
            a += x;
        }
        if (t == 3) {
            mi = min(mi, x);
            mx = min(mx, x);
        }
        if (t == 2) {
            mi = max(mi, x);
            mx = max(mx, x);
        }
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << min(mx, max(mi, x + a)) << "\n";
    }
    return 0;
}
