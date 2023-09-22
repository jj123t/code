/*************************************************************************
	> File Name: f.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 26 Apr 2023 09:34:31 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int k;
map<string, int> dp[20][600];
vector<int> arr(500);
int dr = 20;
int dfs(int idx, bool lim, int show, string s) {
    if (__builtin_popcountll(show) > k) return 1e17;
    if (idx == 0) {
        return 0;
    }
    if (!lim && dp[idx][show][s]) return dp[idx][show][s];
    int la = lim ? arr[idx] : 0;
    int ans = 0;
    for (int i = s.size() - 1, j = 1; i > -1; i--, j *= 10) {
        ans += (ll)(s[i] - '0') * j;
    }
    ans *= pow(10, idx);
    if (dr) {
        cout << s << " " << ans << " " << la  << "\n";
        dr--;
    }
    int tmp = 1e17;
    for (int i = la; i <= 9; i++) {
        int r = (show | (1ll << i));
        if (__builtin_popcountll(r) <= k)
        tmp = min(tmp, dfs(idx - 1, lim && i == la, r, s + to_string(i)));
    }
    ans += tmp;
    if (!lim && __builtin_popcountll(show) <= k) dp[idx][show][s] = ans;
    return ans;
}
int solve(int x) {
    int cnt = 0;
    while (x) {
        arr[++cnt] = x % 10;
        x /= 10;
    }
    for (int i = 0; i <= cnt; i++) cout << arr[i] << " ";
    return dfs(cnt, 1, 0, "0");
}
signed main () {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n >> k;
        cout << solve(n) << "\n";
    }
    return 0;
}
