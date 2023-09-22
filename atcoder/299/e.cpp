/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 22 Apr 2023 07:52:15 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct node {
    int l, r, val;
}tree[N];
void dfs(int u, int p) {
    tree[u].l = dfn[u] = ++timer;
    for (auto v : e[u]) {
        if (u == p) continue;
        dfs(v, u);
    }
    tree[u].r = timer;
}
void add(int i, int x) {
    while (i <= n) {
        tree[i].val += x;
        i += (i & -i);
    }
}
bool qry(int i) {
    bool res = false;
    while (i >= 1) {
        res |= tree[i].val;
        i -= (i & -i);
    }
    return res;
}
int main () {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int q; cin >> q;
    using P = pair<int, int>;
    vector<P> ques(q);
    for (int i = 0; i < q; i++) cin >> ques[i].firsst >> ques[i].second;
    sort(ques.begin(), ques.end(), [&](P a, P b){
            int a = dfn[a.first];
            int b = dfn[a.second];
            return a > b;
            });

    }
    return 0;
}
