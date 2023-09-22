/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 21:24:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
const int N = 2e5 + 10;
vector<int> e[N];
const int p = 998244353;
vector<int> par(N, -1);
vector<int> siz(N, 1);
int Find(int x) {
    if (par[x] < 0) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    if (a == b) {
        siz[a]--;
        return ;
    }
    siz[b] += siz[a] - 1;
    par[a] = b;
}
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        Unite(u, v);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (par[i] < 0) {
            if (siz[i] != 0) {
                ans = 0;
                break;
            }
            ans = (ans * 2) % p;
        }
    }
    cout << ans;
    return 0;
}

