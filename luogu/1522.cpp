/*************************************************************************
	> File Name: 1522.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 18:22:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define db long double
using P = pair<db, db> ;
db INF = 1e18;
double f(P a, P b) {
    return (long double)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
    int n; cin >> n;
    vector<P> point(n + 1);
    for (int i = 1; i <= n; i++) cin >> point[i].first >> point[i].second;
    vector<vector<db>> dis(n + 1, vector<db>(n + 1, INF));
    for (int i = 1; i <= n; i++) dis[i][i] = 0.0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '1') dis[i][j] = f(point[i], point[j]); 
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
    int cnt = 1;
    vector<int> par(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        if (!mp[i]) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] < INF) {
                    par[j] = cnt;
                    mp[j] = true;
                }
            }
            cnt++;
        }
    }
    vector<db> res(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] < INF) {
                res[par[i]] = max(res[par[i]], dis[i][j]);
            }
        }
    }
    db ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] >= INF) {
                db resa = 0;
                for (int k = 1; k <= n; k++) if (k != i and dis[i][k] < INF) resa = max(resa, dis[i][k]);
                db resb = 0;
                for (int k = 1; k <= n; k++) if (k != j and dis[j][k] < INF) resb = max(resb, dis[j][k]);
                db tmp = resa + resb + f(point[i], point[j]);
                ans = min(ans, max({tmp, res[par[i]], res[par[j]]}));
            }
        }
    }
    cout << setprecision(6) << fixed;
    cout << ans << "\n";
    return 0;
}

