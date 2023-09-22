/*************************************************************************
	> File Name: 4185.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 11:28:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
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
int main()
{
    int n, m; cin >> n >> m;
    init(n);
    vector<array<int, 3>> edge(n - 1); 
    for (int i = 0; i < n - 1; i++) cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    sort(edge.begin(), edge.end());
    vector<array<int, 3>> qry(m); 
    for (int i = 0; i < m; i++) { cin >> qry[i][0] >> qry[i][1]; qry[i][2] = i; }
    sort(qry.rbegin(), qry.rend());
    int j = n - 2;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        auto [k, vv, id] = qry[i];
        while (edge[j][0] >= k) {
            auto [w, u, v] = edge[j];
            j--;
            if (!same(u, v)) Unite(u, v);
        }
        ans[id] = siz[Find(vv)] - 1;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    return 0;
}

