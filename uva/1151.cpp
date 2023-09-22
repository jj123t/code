/*************************************************************************
	> File Name: 1151.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 17:17:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
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
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
struct edge {
    int u, v, w;
    edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        init(n + 1);
        vector<int> mess[q + 1];
        for (int i = 1; i <= q; i++) {
            int m; cin >> m;
            int cost; cin >> cost;
            mess[i - 1].push_back(cost);
            for (int j = 1; j <= m; j++) {
                int x; cin >> x;
                mess[i - 1].push_back(x);
            }
        }
        using P = pair<int, int>;
        vector<P> addr(n + 1);
        vector<edge> edges;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1));
        auto compute = [&](int a, int b) -> int {
            auto [x1, y1] = addr[a];
            auto [x2, y2] = addr[b];
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        };
        for (int i = 1; i <= n; i++) cin >> addr[i].first >> addr[i].second;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = compute(i, j);
                edges.push_back({i, j, dist[i][j]});
            }
        }
        int mst = 0;
        vector<edge> eg;
        for (auto [u, v, w] : edges) {
            if (!Same(u, v)) {
                Unite(u, v);
                eg.push_back({u, v, w});
                mst += w;
            }
        }
        int ans = mst;
        for (int i = 0; i < (1 << q); i++) {
            int cost = mst;
            vector<vector<int>> mp(n + 1, vector<int>(n + 1));
            for (int j = 0; j < q; j++) {
                set<int> st;
                if (i >> j & 1) {
                    cost += mess[j][0];
                    for (int k = 1; k < mess[j].size(); k++) {
                        st.insert(mess[j][k]);
                    }
                }
                for (auto [u, v, w] : eg) {
                    if (mp[u][v]) continue;
                    if (st.count(u) and st.count(v)) {
                        mp[u][v] = true;
                        cost -= w;
                    }
                }
            }
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}

