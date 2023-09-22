const int N = 1e5 + 10;
const int INF = 1e9 + 7;
int V, E;
struct edge {
    int from, to, cost;
};
vector<edge> e;
vector<int> d(N);
void short_path(int s) {
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge t = e[i];
            if (d[t.from] != INF && d[t.to] > d[t.from] + t.cost) {
                d[t.to] = d[t.from] + t.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}
bool find_negative_loop() {
    fill(d.begin(), d.end(), 0);
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < E; j++) {
            edge t = e[j];
            if (d[t.to] > d[t.from] + t.cost) {
                d[t.to] = d[t.from] + t.cost;
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}
