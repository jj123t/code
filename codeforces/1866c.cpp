/*************************************************************************
	> File Name: 1866c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep  3 19:52:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 998244353;
const int N = 2e6;
using P = pair<int, int>;
vector<P> e[N];
vector<int> res(N), cnt0(N), cnt1(N), vis(N);
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (auto [v, w] : e[u]) {
        dfs(v);
        int a = res[v] + res[u] % p; 
        int b = (cnt1[u] + w) % p;
        int c = (cnt0[v] + 1 - w) % p;
        int d = c * b % p;
        res[u] = (d + a) % p;
        cnt1[u] = cnt1[u] + cnt1[v] % p;
        cnt0[u] = cnt0[u] + cnt0[v] % p;
        if (w == 0) cnt0[u]++;
        else cnt1[u]++;
    }
}
signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 1; j <= m; j++) {
            int v, w; cin >> v >> w;
            e[i].push_back(P(v, w));
        }
    }
    dfs(1);
    cout << res[1] % p << '\n';
    return 0;
}

