/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 28 Apr 2023 02:59:24 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct node {
    int to, val; 
};
vector<node> e[N];
int main () {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    int INF = 1e9 + 7;
    vector<int> dis(n + 1, INF);
    using P = pair<int, int>;
    for (int i = 1; i <= n; i++) {
        fill(dis.begin(), dis.end(), INF);
        dis[i] = 0;
        priority_queue<P> q; q.push(P(0, i));
        while (!q.empty()) {
            auto [w, u] = q.top(); q.pop();
            w *= - 1;
            if (w != dis[u]) continue;
            for (auto [v, ww] : e[u]) {
                int d = ww + w;
                if (dis[v] > d) {
                    dis[v] = d;
                    q.push(P(-d, v));
                }
            }
        }
        int ans = INF;
        for (int j = 1; j <= n; j++) {
            for (auto [v, w]: e[j]) {
                if (v == i) {
                    ans = min(ans, dis[j] + w);
                }
            }
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}
