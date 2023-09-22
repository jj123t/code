/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May  4 12:49:03 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 500;
int k;
vector<int> arr(N, 0);
map<int, int> dp[N];
int dfs(int idx, int prod, bool lim, bool leadzero) {
    if (idx == 0) {
        return (prod <= k);
    }
    if (!lim && !leadzero && dp[idx][prod]) return dp[idx][prod];
    int la = (lim ? arr[idx] : 9);
    int ans = 0;
    for (int i = 0; i <= la; i++) {
        int x = (leadzero && i == 0 ? 1 : i);
        ans += dfs(idx - 1, prod * x, lim && i == la, leadzero && i == 0);
    }
    if (!lim && !leadzero) dp[idx][prod] = ans;
    return ans;
}
int solve(int x) {
    int cnt = 0;
    while (x) {
        arr[++cnt] = x % 10;
        x /= 10;
    }
    return dfs(cnt, 1, 1, 1);
}
signed main () {
    int n; cin >> n >> k;
    cout << solve(n) - 1;
    return 0;
}

