/*************************************************************************
	> File Name: 3286.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 10 10:08:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int k;
int a[1001000];
using P = pair<int, int>;
map<P, int> mp;
int dfs(int idx, int lim, int s, int p) {
    if (idx == 0) return max(0ll, s);
    if (!lim && mp[P(idx, s)]) return mp[P(idx, s)];
    int ub = (lim ? a[idx] : k - 1);
    int ans = 0;
    for (int i = 0; i <= ub; i++) {
        ans += dfs(idx - 1, lim && i == ub, s + (p == 1 ? i * (idx - 1) : (idx < p) ? -i : i), p);
    }
    return mp[P(idx, s)] = ans;
}
int solve(int x) {
    int cnt = 0;
    while (x) {
        a[++cnt] = x % k;
        x /= k;
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        mp.clear();
        ans += ((i == 1) ? 1 : -1) * dfs(cnt, 1, 0, i);
    }
    return ans;
}
signed main()
{
    int l, r; cin >> l >> r;
    cin >> k;
    cout << solve(r) - solve(l - 1) << "\n";
    return 0;
}

