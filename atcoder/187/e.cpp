/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 04:56:06 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 1e6 + 10;
vector<int> dfn(N, 0);
struct node {
    int l, r, v; 
}tree[N];
int n;
vector<int> e[N];
using P = pair<int, int>;
vector<P> edge(N); 
int cnt = 0;
vector<int> fa(N, 0);
void dfs(int u, int p) {
    fa[u] = p;
    tree[u].l = dfn[u] = ++cnt;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tree[u].r = cnt;
}
void add(int i, int x) {
    while (i <= n) {
        tree[i].v += x;
        i += (i & -i);
    }
}
int qry(int i) {
    int res = 0;
    while (i >= 1) {
        res += tree[i].v;
        i -= (i & -i);
    }
    return res;
}
int sum(int idx) {
    return qry(tree[idx].r) - qry(tree[idx].l - 1);
}
signed main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edge[i] = P(u, v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        int idx; cin >> idx; idx--;
        auto [a, b] = edge[idx];
        int x; cin >> x;
        if (fa[a] == b) {
            swap(a, b);
            if (op == 1) op = 2;
            else op = 1;
        }
        if (op == 1) {
            add(1, x);
            add(tree[b].l, -x);
            add(tree[b].r + 1, x);
        }
        else {
            add(tree[b].l, x);
            add(tree[b].r + 1, -x);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout << dfn[i] << " " << tree[i].l << " " << tree[i].r << "\n";
    }
    */
    for (int i = 1; i <= n; i++) {
        cout << qry(dfn[i]) << "\n";
    }
    return 0;
}
