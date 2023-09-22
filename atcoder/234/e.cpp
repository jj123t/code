/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 21:00:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;
vector<int> a(20, 0);
map<int, int> dp[21][11];
int dfs(int idx, int d, int last, int s, bool lim) {
    if (idx == 0) {
        return s;
    }
    if (!lim && d != INF && dp[idx][last][d]) return dp[idx][last][d];
    int ans = INF;
    if (d == INF) {
        int la = (lim ? a[idx] : 0);
        for (int i = la; i <= 9; i++) {
            ans = min(ans, dfs(idx - 1, i - last, i, s * 10 + i, lim && i == la));
        }
    }
    else {
        if (last + d < 0 || last + d > 10) return INF;
        if (lim && (last + d) < a[idx]) return INF; 
        ans = min(ans, dfs(idx - 1, d, last + d, s * 10 + last + d, lim && (last + d) == a[idx]));
    }
    if (!lim && d != INF) dp[idx][last][d] = ans; 
    return ans;
}
int solve(string s) {
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        a[++cnt] = s[i] - '0';
    }
    int ans = INF;
    for (int i = a[cnt]; i <= 9; i++) {
        ans = min(ans, dfs(cnt - 1, INF, i, i, (i == a[cnt])));
    }
    return ans;
}
signed main()
{
    string s; cin >> s;
    cout << solve(s);
    return 0;
}

