class dsu {
    vector<int> par;
    vector<int> rnk;
public : 
    dsu(int n) {
        par.resize(n + 1);
        rnk.resize(n + 1);
        iota(par.begin(), par.begin() + n + 1, 0);
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return ;
        if (rnk[x] < rnk[y]) par[x] = y;
        else {
            par[y] = x;
            if (rnk[x] == rnk[y]) rnk[x]++;
        }
    }
};
