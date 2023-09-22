/*************************************************************************
	> File Name: 5658.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 17:27:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
vector<int> e[N]; 
vector<int> par(N), last(N), f(N); // f[i] -> 以s[i]结尾的合法子串数
string s;
void dfs(int u) {
    last[u] = last[par[u]];
    if (s[u] == '(') last[u] = u; 
    else if (last[u]) f[u] = f[par[last[u]]] + 1, last[u] = last[par[last[u]]];
    for (auto v : e[u]) {
        if (v == par[u]) continue;
        dfs(v);
    }
}
signed main()
{
    int n; cin >> n;
    cin >> s; s = " " + s;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    dfs(1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        f[i] += f[par[i]];
        ans ^= (i * f[i]);
    }
    cout << ans << "\n";
    return 0;
}

