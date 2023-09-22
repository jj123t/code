/*************************************************************************
	> File Name: 3372.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 18:48:45 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
int tree[4 * N];
int arr[N];
int lazy[4 * N];
void build(int p, int l, int r) {
    if (l == r) { tree[p] = arr[l]; return ; }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
void add(int p, int pl, int pr, int l, int r, int x) {
    if (l <= pl and pr <= r) { tree[p] += (pr - pl + 1) * x; lazy[p] += x; return; }
    int mid = (pl + pr) / 2;
    if (lazy[p] and pl != pr) {
        tree[p * 2] += lazy[p] * (mid - pl + 1), lazy[p * 2] += lazy[p];
        tree[p * 2 + 1] += lazy[p] * (pr - (mid + 1) + 1), lazy[p * 2 + 1] += lazy[p];
        lazy[p] = 0;
    }
    if (mid >= l) add(p * 2, pl, mid, l, r, x);
    if (mid < r) add(p * 2 + 1, mid + 1, pr, l, r, x);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
int qry(int p, int pl, int pr, int l, int r) {
    if (l <= pl and pr <= r) return tree[p]; 
    int mid = (pl + pr) / 2;
    if (lazy[p]) {
        tree[p * 2] += lazy[p] * (mid - pl + 1), lazy[p * 2] += lazy[p];
        tree[p * 2 + 1] += lazy[p] * (pr - (mid + 1) + 1), lazy[p * 2 + 1] += lazy[p];
        lazy[p] = 0;
    }
    int ans = 0;
    if (l <= mid) ans += qry(p * 2, pl, mid, l, r);
    if (r > mid) ans += qry(p * 2 + 1, mid + 1, pr, l, r);
    return ans;
}
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, k; cin >> x >> y >> k;
            add(1, 1, n, x, y, k);
        }
        else {
            int x, y; cin >> x >> y;
            cout << qry(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}

