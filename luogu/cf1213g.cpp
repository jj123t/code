/*************************************************************************
	> File Name: cf1213g.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 13:10:14 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 10;
vector<int> par(N), siz(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, siz[i] = 1;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    int a = Find(x), b = Find(y);
    siz[b] += siz[a];
    par[a] = b;
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    init(n);
    vector<array<int, 3>> edge(n - 1); 
    for (int i = 0; i < n - 1; i++) cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    sort(edge.begin(), edge.end());
    vector<array<int, 2>> qry(m);
    for (int i = 0; i < m; i++) { cin >> qry[i][0]; qry[i][1] = i; }
    sort(qry.begin(), qry.end());
    int j = 0;
    vector<int> ans(m);
    int res = 0;
    for (int i = 0; i < m; i++) {
        auto [k, id] = qry[i];
        while (j < n - 1 and edge[j][0] <= k) {
            auto [w, u, v] = edge[j];
            j++;
            int a = siz[Find(u)];
            int b = siz[Find(v)];
            res -= a * (a - 1) / 2 + b * (b - 1) / 2;
            Unite(u, v);
            int c = siz[Find(u)];
            res += c * (c - 1) / 2;
        }
        ans[id] = res;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    return 0;
}
