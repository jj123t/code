/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 10 Apr 2023 09:22:39 PM CST
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 1e6 + 10;
int arr[N];
int dp[N][2];
int dfs(int idx, int lim) {
    if (idx == 0) {
        return 0;
    }
    if (dp[idx][lim] != -1) return dp[idx][lim];
    int res = 1e9 + 7;
    if (!lim) {
        int x = arr[idx];
        res = min(res, dfs(idx - 1, 0) + x);
        res = min(res, dfs(idx - 1, 1) + x + 1);
    }
    else {
        int x = arr[idx];
        if (idx <= 1) {
            x = 10 - x;
        }
        else {
            x = 9 - x;
        }
        res = min(res, dfs(idx - 1, 1) + x);
        res = min(res, dfs(idx - 1, 0) + x + 1);
    }
    dp[idx][lim] = res;
    return res;
}
int solve(string s) {
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        arr[++cnt] = s[i] - '0';
    }
    return dfs(cnt, 1);
}
signed main() {
    string s; cin >> s;
    cout << solve(s);
    return 0;
}
