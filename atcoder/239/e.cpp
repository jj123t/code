/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 19 04:51:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
    int l, r, val;
}tree[N];
vector<int> e[N];
int timer = 0;
vector<int> rnk(N, 0);
void dfs(int u, int p) {
    tree[u].l = timer;
    rnk[timer++] = u;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tree[u].r = timer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> tree[i].val;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, 0);

    const int B = 360;
    vector<int> bucket[B];
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        bucket[i / B].push_back(tree[rnk[i]].val);
        num[i] = tree[rnk[i]].val;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n / B; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << tree[i].l << " ";
    }
    cout << '\n';
    */
    for (int i = 0; i < q; i++) {
        int u, k; cin >> u >> k; u--;
        int l = tree[u].l, r = tree[u].r;
        //cout << "l and r : " << l << " " << r << "\n";
        k = (r - l) - k + 1;
        //cout << k << "\n";
        int lb = -1, rb = n - 1;
        while (rb - lb > 1) {
            int mid = lb + rb >> 1;
            int x = num[mid];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl % B != 0) if (tree[rnk[tl++]].val <= x) c++;
            while (tl < tr && tr % B != 0) if (tree[rnk[--tr]].val <= x) c++;
            while (tl < tr) {
                int b = tl / B;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += B;
            }
            if (c >= k) rb = mid;
            else lb = mid;
        }
        cout << num[rb] << '\n';
    }
    return 0;
}

