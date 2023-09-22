/*************************************************************************
	> File Name: 3384.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 11:57:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
void dfs1(int u, int p) {
    par[u] = p;
    dep[u] = dep[p] + 1;
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (!son[u] or siz[v] > siz[son[u]]) {
            son[u] = v;
        }
    }
}
void dfs2(int u, int s) {
    dfn[u] = ++cnt;
    rnk[cnt] = w[u];
    top[u] = s;
    if (!son[u]) return;
    dfs2(son[u], s);
    for (auto v : e[u]) {
        if (v == par[u] or v == son[u]) continue;
        dfs2(v, v);
    }
}

void build(int p, int l, int r) {
    if (l == r) { tree[p] = rnk[l]; }
    int mid = l + r >> 1;
    build(p * 2, l, mid); build(p * 2 + 1, mid + 1, r);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
void push_down(int p, int l, int r) {
    int mid = l + r >> 1;
    tree[p * 2] += lazy[p] * (mid - l + 1); lazy[p * 2] += lazy[p];
    tree[p * 2 + 1] += lazy[p] * (r - mid); lazy[p * 2 + 1] += lazy[p];
    lazy[p] = 0;
}
void add(int p, int l, int r, int s, int t, int  x) {
    if (s <= l and r <= t) { tree[p] += (r - l + 1) * x; lazy[p] += x; return; }
    int mid = l + r >> 1;
    push_down(p, l, r);
    if (mid >= s) add(p * 2, l, mid, s, t, x);
    if (mid < t) add(p * 2 + 1, mid + 1, r, s, t, x);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
int qry(int p, int l, int r, int s, int t) {
    if (s <= l and r <= t) { return tree[p]; }
    int mid = l + r >> 1, ans = 0;
    push_down(p, l, r);
    if (mid >= s) ans += qry(p * 2, l, mid, s, t);
    if (mid < t) ans += qry(p * 2 + 1, mid + 1, r, s, t);
    return ans;
}
int 
int main()
{
    int n, m, r, p; cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(r, 0); dfs2(r, r); build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op; cin >> op;
        if (op == 1) {
            int u, v, z; cin >> u >> v >> z;
        }
        else if (op == 2) {
            int u, v; cin >> u >> v;
        }
        else if (op == 3) {
            int u, z; cin >> u >> z;
        }
        else {
            int u; cin >> u;
        }
    }
    return 0;
}

