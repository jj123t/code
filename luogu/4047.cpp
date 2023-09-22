/*************************************************************************
	> File Name: 4047.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 12:25:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define db long double
using P = pair<db, db>;
const int N = 1e3 + 10;
int par[N];
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
db f(P a, P b) {
    db x = a.first - b.first;
    db y = a.second - b.second;
    return sqrt(x * x + y * y);
}
int main()
{
    int n, k; cin >> n >> k;
    init(n);
    vector<P> point(n + 1);
    for (int i = 1; i <= n; i++) cin >> point[i].first >> point[i].second;
    using tp = tuple<db, int, int>;
    priority_queue<tp, vector<tp>, greater<tp>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            q.push({f(point[i], point[j]), i, j});
        }
    }
    priority_queue<db> ans;
    while (!q.empty()) {
        auto [d, u, v] = q.top(); q.pop();
        if (!same(u, v)) {
            Unite(u, v);
            ans.push(d);
        }
    }
    for (int i = 0; i < k - 2; i++) ans.pop();
    cout << setprecision(2) << fixed ;
    cout << ans.top() << "\n";
    return 0;
}

