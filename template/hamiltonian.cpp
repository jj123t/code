int n;
int e[500][500];
int vis[500];
bool dfs(int u, int step) {
    if (step >= n) {
        if (e[u][1]) {
            cout << 1 << " ";
            return true;
        }
        return false;
    }
    for (int i = 2; i <= n; i++) {
        if (e[u][i] and !vis[i]) {
            vis[i] = true;
            if (dfs(i, step + 1)) {
                cout << i << " ";
                return true;
            }
            vis[i] = false;
        }
    }
    return false;
}
