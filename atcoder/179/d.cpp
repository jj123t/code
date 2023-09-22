/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 17 Apr 2023 08:29:04 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int p = 998244353;
signed main () {
    int n, k; cin >> n >> k;
    using P = pair<int, int>;
    vector<P> arr(k);
    for (int i = 0; i < k; i++) cin >> arr[i].first >> arr[i].second;
    vector<int> dp(n + 2, 0);
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % p;
        for (int j = 0; j < k; j++) {
            int l = arr[j].first, r = arr[j].second;
            int tol = min(i + l, n + 1), tor = min(i + r + 1, n + 1);
            dp[tol] = (dp[tol] + dp[i] ) % p;
            dp[tor] = (dp[tor] - dp[i] + p) % p;
        }
    }
    cout << dp[n];
    return 0;
}
