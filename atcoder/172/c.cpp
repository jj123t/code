/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 01:25:02 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n), B(m);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    vector<int> pfxa(n + 1, 0), pfxb(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        pfxa[i] = pfxa[i - 1] + A[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        pfxb[i] = pfxb[i - 1] + B[i - 1];
    }
    int ans = 0;
    int j = m;
    for (int i = 0; i <= n; i++) {
        if (pfxa[i] > k) break;
        while (pfxb[j] > k - pfxa[i]) j--;
        ans = max(ans, i + j);
    }
    cout << ans;
    return 0;
}
