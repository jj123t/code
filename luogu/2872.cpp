/*************************************************************************
	> File Name: 2872.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 19:05:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 1e6;
using ll = long long;
using P = pair<db, db>;
db f(P a, P b) {
    db dx = a.first - b.first;
    db dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
vector<int> par(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
} 
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    init(n);
    vector<P> point(n + 1);
    for (int i = 1; i <= n; i++) {
        db x, y; cin >> x >> y;
        point[i] = {x, y};
    }
    using tp = tuple<db, int, int>;
    vector<tp> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            db x = f(point[i], point[j]);
            edges.push_back({x, i, j});
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edges.push_back({0.0, u, v});
    }
    sort(edges.begin(), edges.end());
    db mst = 0;
    for (auto [x, u, v] : edges) {
        if (!same(u, v)) {
            mst += x;
            Unite(u, v);
        }
    }
    cout << setprecision(2) << fixed ;
    cout << mst;
    return 0;
}

