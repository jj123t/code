/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 30 Apr 2023 08:54:22 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
using P = pair<int, int>;;
P crt(vector<int> a, vector<int> b) {
    int n = a.size();
    int LCM = 1;
    int pc = 1;
    for (int i = 0; i < n; i++) {
        LCM = lcm(b[i], LCM);
        pc *= b[i];
    }
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        int res = 1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            res = lcm(res, b[j]);
        }
        tmp += a[i] * res;
    }
    return P(-tmp / LCM, (pc == LCM ? LCM : 0));
}
signed main () {
    int tt; cin >> tt;
    while (tt--) {
        int x, y, p, q; cin >> x >> y >> p >> q;
        int ans = 1e9;
        for (int a = x; a < x + y; a++) {
            for (int b = p; b < p + q; b++) {
                auto [r, t] = crt({a, b}, {2 * x + 2 * y, p + q});
                if (t == 0) continue;
                ans = min(ans, r);
            }
        }
        if (ans == 1e9) cout << "infinity" << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
