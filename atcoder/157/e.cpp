/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 12:31:09 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 4e6 + 10;
struct node {
    int l, r, v;
};
string s;
node tree[N];
void build(int  p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].v = (1 << (s[l] - 'a'));
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].v = tree[p * 2].v | tree[p * 2 + 1].v;
}
void update(int p, int l, int r, int x, int y) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].v &= ~(1 << y);
        tree[p].v |= (1 << x);
        return;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if (l <= mid) update(p * 2, l, mid, x, y);
    if (r > mid) update(p * 2 + 1, mid + 1, r, x, y);
    tree[p].v = tree[p * 2].v | tree[p * 2 + 1].v;
}
int qry(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].v;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if (l <= mid) ans |= qry(p * 2, l, mid);
    if (r > mid) ans |= qry(p * 2 + 1, mid + 1, r);
    return ans;
}
signed main () {
    int n; cin >> n;
    cin >> s;
    s = "0" + s;
    build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l; char c; cin >> l >> c;
            int x = c - 'a';
            update(1, l, l, x, s[l] - 'a');
        }
        else {
            int l, r; cin >> l >> r;
            int x = qry(1, l, r);
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                if (x >> i & 1) ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
