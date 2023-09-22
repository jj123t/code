/*************************************************************************
	> File Name: 1991.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 23:08:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
double f(P a, P b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
vector<int> par(600);
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
    int s, m; cin >> s >> m;
    init(m + 1);
    vector<P> point(m + 1);
    for (int i = 1; i <= m; i++) cin >> point[i].first >> point[i].second;
    using tp = tuple<double, int, int>;
    priority_queue<tp, vector<tp>, greater<tp>> q;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            q.push({f(point[i], point[j]), i, j});
        }
    }
    priority_queue<double> ans;
    while (!q.empty()) {
        auto [d, i, j] = q.top(); q.pop();
        if (!same(i, j)) {
            Unite(i, j);
            ans.push(d);
        }
    }
    while (--s) {
        ans.pop();
    }
    cout << setprecision(2) << fixed ;
    cout << ans.top() << "\n";
    return 0;
}

