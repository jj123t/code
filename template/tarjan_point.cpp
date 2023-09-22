const int N = 1e5;
int dfn[N], low[N], timer;
vector<int> cut(N), e[N];
void tarjan(int u) {
    dnf[u] = low[u] = ++timer;
    int son = 0;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                son++;
                if (u != root or son > 1) cut.push_back(u);
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

