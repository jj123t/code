/*************************************************************************
	> File Name: 1378.cpp
	> Author:123emm
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 21 08:26:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

using P = pair<double, double>;
using PP = pair<int, double>;
double xa, xb, ya, yb;
vector<P> p(10);
double pi = 4.0 * atan(1);
int n;
double ans = 0.0;

double Extend(int idx) {
    auto [x, y] = p[idx];
    double r = min({fabs(x - xa), fabs(x - xb), fabs(y - ya), fabs(y - yb)});
    return r;
}

void dfs(int idx, set<pair<int, double>> res, set<int> vis) {
    if (idx == n) {
        double t = 0;
        for (auto [id, r] : res) {
            t += pi * r * r;
        }
        ans = max(ans, t);
        return ;
    }
    for (int i = 0; i < n; i++) {
        auto [x, y] = p[i];
        if (vis.count(i)) {
            continue;
        }
        else {
            double t = Extend(i);
            bool flag = false;
            for (auto [id, r] : res) {
                double d = sqrt((x - p[id].first) * (x - p[id].first) + (y - p[id].second) * (y - p[id].second));
                if (d <= r) flag = true;
                t = min(t, d - r);
            }
            if (flag) {
                vis.insert(i);
                dfs(idx + 1, res, vis);
                vis.erase(i);
            }
            else {
                res.insert(PP(i, t));
                vis.insert(i);
                dfs(idx + 1, res, vis);
                res.erase(PP(i, t));
                vis.erase(i);
            }
        }
    }
}
int main()
{
    cin >> n;
    cin >> xa >> ya >> xb >> yb;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    set<PP> res; set<int> vis;
    dfs(0, res, vis);
    double r = fabs(xa - xb) * fabs(ya - yb);
    cout << int(r - ans + 0.5) << '\n';
    return 0;
}


