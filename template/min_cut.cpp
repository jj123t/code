const int N = 1e5;
int n, m, s, t;
int level[N], now[N], be[N];
vector<array<int, 3>> e[N];
const int INF = 1e9;
bool bfs() {
    for (int i = 1; i <= n; i++) level[i] = INF;
    queue<int> q; q.push(s);
    level[s] = 0; be[s] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [v, w, id] : e[u]) {
            if (w > 0 and level[v] == INF) {
                q.push(v);
                be[v] = 0;
                level[v] = level[u] + 1;
                if (v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, int flow) {
    if (u == t or !flow) return flow;
    int res = 0;
    for (int i = be[u]; i < e[u].size(); i++) {
        be[u] = i;
        auto &[v, w, id] = e[u][i];
        if (w > 0 and level[v] == level[u] + 1) {
            int maxnow = dfs(v, min(flow, w));
            if (maxnow == 0) level[v] = INF;
            w -= maxnow;
            e[v][id][1] += maxnow;
            res += maxnow;
            flow -= maxnow;
        }
    }
    return res;
}
signed main()
{
    cin >> n >> m >> s >> t; 
    // 拆点
    s += n;
    for (int i = 1; i <= n; i++) { 
        // 删点 -> 点转化为入点与出点，删点即删除入点与出点的边
        int a = e[i].size(), b = e[i + n].size();
        e[i].push_back({i + n, 1, b});
        e[i + n].push_back({i, 0, a});
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        // 联通即可： 代表二点间容量无穷大
        int a = e[v].size(), b = e[u + n].size();
        e[u + n].push_back({v, INF, a});
        e[v].push_back({u + n, 0, b});

        a = e[v + n].size(), b = e[u].size();
        e[u].push_back({v + n, 0, a});
        e[v + n].push_back({u, INF, b});
    }
    int ans = 0;
    n = n * 2; 
    // 图点数增加
    while (bfs()) {
        ans += dfs(s, INF);
    }
    cout << ans << "\n";
    return 0;
}


