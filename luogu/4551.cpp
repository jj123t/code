/*************************************************************************
	> File Name: 4551.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 30 22:34:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
using P = pair<int, int>;
int trie[N][2];
int exist[N];
vector<P> e[N];
vector<int> f(N);
int cnt = 0;
void insert(int u) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        int x = u >> i & 1;
        if (!trie[p][x]) trie[p][x] = ++cnt;
        p = trie[p][x];
    }
}
int qry(int u) {
    int p = 0;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        int x = u >> i & 1;
        if (!trie[p][x ^ 1]) p = trie[p][x];
        else p = trie[p][x ^ 1], ans += (1 << i);
    }
    return ans;
}
void dfs(int u, int p) {
    for (auto [v, w] : e[u]) {
        if (v == p) continue;
        f[v] = f[u] ^ w;
        insert(f[v]);
        dfs(v, u);
    }
}
signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, qry(f[i]));
    }
    cout << ans << "\n";
    return 0;
}

