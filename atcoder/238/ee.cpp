/*************************************************************************
	> File Name: ee.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 19:06:14 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N = 1e6 + 10;
vector<int> par(N, 0);
int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
int main()
{
    int n, m; cin >> n >> m;
    iota(par.begin(), par.begin() + n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        Unite(u - 1, v);
    }
    cout << (Same(0, n) ? "Yes" : "No");
    return 0;
}

