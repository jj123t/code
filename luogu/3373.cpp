/*************************************************************************
	> File Name: 3373.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 21:31:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5 + 1000;
int tree[4 * N];
vector<int> lazy_mul(N * 4, 1);
int lazy_add[4 * N];
int a[N];
int m;
using ll = long long;
void down(int p, int l, int r) {
    if (l == r or (lazy_add[p] == 0 and lazy_mul[p] == 1)) return;
    int mid = l + r >> 1;
    tree[p * 2 + 1] = (tree[p * 2 + 1] * lazy_mul[p] + lazy_add[p] * (r - mid)) % m;
    tree[p * 2] = (tree[p * 2] * lazy_mul[p] + lazy_add[p] * (mid - l + 1)) % m;


}
void build(int p, int l, int r) {
    lazy_add[p] = 0, lazy_mul[p] = 1;
    if (l == r) { tree[p] = a[l] % m; return; }
    int mid = (l + r) / 2;
    build(p * 2, l, mid); build(p * 2 + 1, mid + 1, r);
    tree[p] = tree[p * 2] + tree[p * 2 + 1] % m;
}
void down(int p, int l, int r) {
}
void add(int p, int l, int r, int s, int t, int x) {
    if (s <= l and r <= t) { 
        tree[p] = (tree[p] + (ll)x * (r - l + 1)) % m;
        lazy_add[p] = lazy_add[p] + x; 
        return;
    }
    int mid = (l + r) / 2;
    down(p, l, r);
    if (mid >= s) add(p * 2, l, mid, s, t, x);
    if (mid < t) add(p * 2 + 1, mid + 1, r, s, t, x);
    tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % m;
}
//
void mul(int p, int l, int r, int s, int t, int x) {
    if (s <= l and r <= t) { 
        tree[p] = ((tree[p] * x) % m);
        lazy_mul[p] = ((lazy_mul[p] * x) % m); 
        lazy_add[p] = ((lazy_add[p] * x) % m);
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (mid >= s) mul(p * 2, l, mid, s, t, x);
    if (mid < t) mul(p * 2 + 1, mid + 1, r, s, t, x);
    tree[p] = ((tree[p * 2] + tree[p * 2 + 1]) % m);
}
//
int qry(int p, int l, int r, int s, int t) {
    if (s <= l and r <= t) { return tree[p]; }
    int ans = 0;
    int mid = (l + r) / 2;
    down(p, l, r);
    if (mid >= s) ans = (ans + qry(p * 2, l, mid, s, t)) % m;
    if (mid < t) ans = (ans + qry(p * 2 + 1, mid + 1, r, s, t)) % m;
    return ans % m;
}
//
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, k; cin >> x >> y >> k;
            mul(1, 1, n, x, y, k % m);
        }
        else if (op == 2) {
            int x, y, k; cin >> x >> y >> k;
            add(1, 1, n, x, y, k % m);
        }
        else {
            int x, y; cin >> x >> y;
            cout << qry(1, 1, n, x, y) % m << "\n";
        }
    }
    return 0;
}
