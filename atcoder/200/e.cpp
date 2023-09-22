/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 02:13:36 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll g(ll n) {
    if (n <= 2) return 0;
    return (n - 1) * (n - 2) / 2;
}
ll f(ll x, ll n) {
    return g(x) - 3 * g(x - n) + 3 * g(x - 2 * n) - g(x - 3 * n);
}
signed main () {
    ll n, k; cin >> n >> k;
    for (ll i = 3; i <= 3 * n; i++) {
        ll x = f(i, n);
        if (k <= x) {
            for (ll j = 1; j <= n; j++) {
                ll mi = max(1ll, i - j - n);
                ll mx = min(n, i - j - 1ll);
                if (mi > mx) continue;
                if (k > mx - mi + 1) {
                    k -= mx - mi + 1ll;
                    continue;
                }
                cout << j << " " << ll(mi + k - 1ll) << " " << ll(i - j - (mi + k - 1ll)) << '\n';
                return 0;
            }
        }
        k -= x;
    }
    return 0;
}
