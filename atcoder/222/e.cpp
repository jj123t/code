/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat May 13 19:58:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 998244353;
const int N = 2e5 + 10;
using P = pair<int, int>;
vector<P> e[N];
vector<int> cnt(N, 0);
int dfs(int u, int p, int t) {
    if (u == t) {
        return 1;
    }
    for (auto [v, id]: e[u]) {
        if (v == p) continue;
        if (dfs(v, u, t)) {
            cnt[id]++;
            return 1;
        }
    }
    return 0;
}

signed main()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    for (int i = 0; i < m - 1; i++) {
        dfs(A[i], -1, A[i + 1]);
    }
    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        s += cnt[i];
    }
    if ((s + k) % 2 || s + k < 0) {
        cout << 0;
        return 0;
    }
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = N - 1; j - cnt[i] >= 0; j--) {
            dp[j] += dp[j - cnt[i]];
            dp[j] %= p;
        }
    }
    cout << dp[(s + k) / 2];
    return 0;
}

