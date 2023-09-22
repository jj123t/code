/*************************************************************************
  > File Name: 12532.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sun Sep  3 08:53:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
    int v, tag = 1;
}tree[N * 4];
int dt[N];
int qpow(int a, int b) {
    if (a == 0) return 0;
    else if (a < 0) { return ((b % 2 == 0) ? 1 : -1); }
    else return 1;
}
void down(int p, int l, int r) { tree[p].v = tree[p * 2].v * tree[p * 2 + 1].v; }
void build(int p, int l, int r) {
    if (l == r) tree[p].v = qpow(dt[l], 1), tree[p].tag = 1;
    else {
        int mid = l + r >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        down(p, l, r);
    }
}
void update(int p, int l, int r, int ql, int qr, int x) {
    if (l == r) tree[p].v = qpow(x, 1);
    else {
        int mid = l + r >> 1;
        if (ql <= mid) update(p * 2, l, mid, ql, qr, x);
        if (qr > mid) update(p * 2 + 1, mid + 1, r, ql, qr, x);
        down(p, l, r);
    }
}
int qry(int p, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) return qpow(tree[p].v, 1);
    int mid = l + r >> 1;
    int ans = 1;
    if (ql <= mid) ans *= qry(p * 2, l, mid, ql, qr);
    if (qr > mid) ans *= qry(p * 2 + 1, mid + 1, r, ql, qr);
    return ans;
}
int main()
{
    int n, q;
    while (cin >> n >> q) { 
        for (int i = 1; i <= n; i++) cin >> dt[i];
        build(1, 1, n);
        string s = "";
        while (q--) {
            char op; cin >> op;
            if (op == 'C') {
                int idx, x; cin >> idx >> x;
                update(1, 1, n, idx, idx, x);
            }
            else {
                int l, r; cin >> l >> r;
                int x = qry(1, 1, n, l, r);
                //cout << x << '\n';
                if (x < 0) s += '-';
                else if ( x == 0 ) s += '0';
                else s += '+';
            }
        }
        cout << s << '\n';
    }
    return 0;
}

