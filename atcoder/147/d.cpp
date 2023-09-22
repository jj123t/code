/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 13 Apr 2023 05:24:00 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
ll p = 1e9 + 7;
signed main () {
    ll n; cin >> n;
    vector<ll> arr(61, 0);
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        for (ll j = 0; j < 61; j++) {
            arr[j] += (x >> j & 1ll);
        }
    }
    ll ans = 0;
    for (ll i = 0, res = 1; i < 60; i++, res = (res * 2) % p) {
        ll a = arr[i] * (n - arr[i]) % p;
        ll b = a * res;
        ans = (ans + b) % p;
    }
    cout << ans;
    return 0;
}
