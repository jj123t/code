const int N = 1e5 + 10;
const int INF = 1e9 + 7;
using P = pair<int, int>;
vector<P> e[N];
vector<int> d(N, INF);
vector<bool> vis(N, false);
int prim() {
    priority_queue<P, vector<P>, greater<P>> q;
    int mst = 0;
    int cnt = 0;
    vis[1] = true;
    q.push(P(0, 1));
    while (!q.empty()) {
        auto [w, v] = q.top(); q.pop();
        mst += w;
        cnt++;
        for (auto [cost, u] : e[v]) {
            if (vis[u]) continue;
            vis[u] = true;
            if (d[u] > d[v] + cost) {
                d[u] = d[v] + cost;
                q.push({d[u], u});
            }
        }
    }
    return mst;
}
