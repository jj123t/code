/*************************************************************************
  > File Name: 1232.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Sep  2 20:58:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int INF = -1e9;
struct node {
    int v, tag;
}tree[2000100];
void push_up(int p, int l, int r) {
    if (tree[p].tag >= 0) {
        tree[p * 2].v = tree[p].tag;
        tree[p * 2 + 1].v = tree[p].tag;
        tree[p * 2].tag = tree[p].tag;
        tree[p * 2 + 1].tag = tree[p].tag;
        tree[p].tag = INF;
    }
}
void push_down(int p, int l, int r) {
    tree[p].v = min(tree[p * 2].v, tree[p * 2 + 1].v);
}
void build(int p, int l, int r) {
    if (l == r) {
        tree[p].tag = INF;
        tree[p].v = 0;
    }
    else {
        int mid = l + r >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        push_down(p, l, r);
    }
}
int ans = 0;
void update(int p, int l, int r, int ql, int qr, int x) {
    if (tree[p].v > x) return ;
    if (ql <= l and r <= qr) {
        if (tree[p].tag <= x and tree[p].tag != INF) {
            ans += (r - l + 1);
            tree[p].v = tree[p].tag = x;
            return ;
        }
    }
    push_up(p, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update(p * 2, l, mid, ql, qr, x);
    if (qr > mid) update(p * 2 + 1, mid + 1, r, ql, qr, x);
    push_down(p, l, r);
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        build(1, 1, 100100);
        ans = 0;
        tree[1].tag = 0;
        for (int i = 1; i <= n; i++) {
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, 100100, l, r - 1, x);
        }
        cout << ans << "\n";
    }
    return 0;
}
