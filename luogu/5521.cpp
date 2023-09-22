/*************************************************************************
	> File Name: 5521.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 08:40:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
vector<int> w(N), ans(N), son[N];
void dfs(int u) {
    ans[u] = w[u];
    for (auto v : son[u]) {
        ans[u] += w[v];
        dfs(v);
    }
    sort(son[u].begin(), son[u].end(), [&](int a, int b) { return ans[a] - w[a] > ans[b] - w[b]; });
    int s = 0;
    for (auto v : son[u]) {
        ans[u] = max(ans[u], ans[v] + s);
        s += w[v];
    }
}
signed main()
{
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        son[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

