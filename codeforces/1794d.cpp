/*************************************************************************
	> File Name: 1794d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 15:29:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int pw(int a, int b) {
    const int p = 998244353;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int iv(int x) {
    int p = 998244353;
    return pw(x, p - 2);
}
signed main()
{
    int n; cin >> n;
    vector<int> vis(1000100, false);
    for (int i = 2; i <= 1000000; i++) {
        if (!vis[i]) 
        for (int j = 2 * i; j <= 1000000; j += i) {
            vis[j] = true;
        }
    }
    const int p = 998244353;
    vector<int> fact(1000100, 1), inv(1000100, 0);
    for (int i = 1; i <= 1000000; i++) fact[i] = fact[i - 1] * i % p;
    for (int i = 1; i <= 1000000; i++) inv[i] = inv[i - 1] * iv(i) % p;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> arr[i];
    vector<int> prime, coprime;
    for (int i = 0; i < 2 * n; i++) {
        if (vis[arr[i]]) coprime.push_back(arr[i]);
        else prime.push_back(arr[i]);
    }
    int ans = fact[n];
    for (auto x : coprime) ans = ans * fact[x] % p;
    int cur = 0;
    vector<int> c(1000100);
    for (auto x : prime) c[++cur] = x;
    vector<vector<int>> dp(cur + 1, vector<int>(cur + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= cur; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * inv[c[i] % p]) % p;
        }
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * inv[(c[i] - 1) % p]) % p;
        }
    }
    cout << dp[cur][n] * ans % p;
    return 0;
}

