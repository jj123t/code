
#define int long long 
const int N = 5500;
const int INF = 1e9;
int dis[N], cur[N], lnk[N], vis[N];
vector<array<int, 4>> e[N];
int n, m;
int ret;
bool spfa(int s, int t) {
    fill(dis, dis + n + 1, INF);
    memcpy(cur, lnk, sizeof(lnk));
    queue<int> q; q.push(s);
    dis[s] = 0, vis[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = lnk[u]; i < e[u].size(); i++) {
            auto &[v, w, c, id] = e[u][i];
            if (w > 0 and dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                if (!vis[v]) q.push(v), vis[v] = true;
            }
        }
    }
    return dis[t] != INF;
}
int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    vis[u] = true; 
    int ans = 0;
    for (int i = cur[u]; i < e[u].size() and ans < flow; i++) {
        cur[u] = i;
        auto &[v, w, c, id] = e[u][i];
        if (!vis[v] and w > 0 and dis[v] == dis[u] + c) {
            int x = dfs(v, t, min(w, flow - ans));
            if (x) {
                ret += x * c;
                w -= x;
                e[v][id][1] += x;
                ans += x;
            }
        }
    }
    vis[u] = false;
    return ans;
}
int mcmf(int s, int t) {
    int ans = 0;
    while (spfa(s, t)) {
        int x;
        while (x = dfs(s, t, INF)) ans += x;
    }
    return ans;
}
signed main()
{
    int s, t;
    cin >> n >> m >> s >> t;
    while (m--) {
        int u, v, w, c; cin >> u >> v >> w >> c;
        int a = e[u].size(), b = e[v].size();
        e[u].push_back({v, w, c, b});
        e[v].push_back({u, 0, -c, a});
    }
    int ans = mcmf(s, t);
    cout << ans << " " << ret << "\n";
    return 0;
}

