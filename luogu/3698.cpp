/*************************************************************************
	> File Name: 3698.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  8 09:24:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int N, K, s, t;
vector<int> e[MAXN];
int dep[MAXN];
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N - 1; i++) {
        int u, v; cin >> u >> v;
        u++, v++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int mx = 0;
    for (int i = 1; i <= N; i++) mx = max(mx, dep[i]);
    int d = mx - 1;
    int ans = 1;
    if (d >= K) {
        ans += K;
    }
    else {
        ans += d;
        K -= d;
        ans += min((N - d - 1) * 2, K) / 2;
    }
    cout << ans << "\n";
    return 0;
}

