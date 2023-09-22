const int N = 1000;
const int INF = 1e9 + 7;
int cost[N][N];
vector<int> d(N);
vector<bool> vis(N);
vector<int> pre(N, -1);
int V, E;
void dijistra(int s) {
    fill(d.begin(), d.begin() + V, INF);
    fill(vis.begin(), vis.begin() + V, false);
    d[s] = 0;
    while (true) {
        int v = -1;
        for (int i = 0; i < V; i++) {
            if (!vis[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if (v == -1) break;
        vis[v] = true;
        for (int u = 0; u < V; u++) {
            if (d[u] < d[v] + cost[v][u]) { 
                d[u] = d[u], d[v] + cost[v][u];
                pre[u] = v;
            }
        }
    }
}
using P = pair<int, int>;
vector<P> e[N];
void dijistra_heap(int s) {
    fill(d.begin(), d.begin() + V, INF); d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q; q.push({0, s});
    while (!q.empty()) {
        auto [w, u] = q.top(); q.pop();
        if (d[u] < w) continue;
        for (auto [v, cost] : e[u]) {
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                pre[v] = u;
                q.push({d[v], v});
            }
        }
    }
}
vector<int> get_path(int t) {
    vector<int> path;
    for (; t != -1; t = pre[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}
