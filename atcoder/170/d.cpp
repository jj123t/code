/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 15 Apr 2023 09:15:58 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    cin.tie(0)->sync_with_stdio(0);

    constexpr ll mod = 998244353;
    vector<ll> pw; pw.reserve(600000);
    pw.push_back(1);
    for (int i = 0; i < 600002; i++) {
        pw.push_back(pw.back() * 10 % mod);
    }

    int q; cin >> q;
    vector<int> dig; dig.reserve(q);
    dig.push_back(1);
    int ptr = -1;
    ll ans = 1;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            dig.push_back(x);
            ans = ans * 10 + x;
            ans %= mod;
        } else if (t == 2) {
            ptr++;
            // dig[ptr] * len % mod + x % mod = ans
            ans += mod - ((ll)dig[ptr] * pw[dig.size()-ptr-1] % mod);
            if (ans >= mod) ans -= mod;
            if (ans < 0) ans += mod;
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
