/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 08:33:27 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
#define int long long 
int p = 1e9 + 7;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
signed main () {
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> cnt(k + 1, 0);
    for (int i = k; i >= 1; i--) {
        int d = k / i;
        cnt[i] = mypow(d, n);
        for (int j = 2 * i; j <= k; j += i) {
            cnt[i] = (cnt[i] - cnt[j] + p) % p;
        }
        ans = (ans + cnt[i] * i % p) % p;
    }
    cout << ans;
    return 0;
}
