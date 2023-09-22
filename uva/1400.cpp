/*************************************************************************
	> File Name: 1400.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep  6 18:09:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int INF = 1e9 + 7;
struct node {
    int prefix, suffix, mx;
} tree[N];
node combine(node a, node b) {
    if (a.mx == -INF) return b;
    else if (b.mx == -INF) return a;
    node c;
    c.prefix = a.prefix;
    c.suffix = b.suffix;
    c.mx = max({a.prefix, b.suffix, a.suffix + b.prefix});
    return c;
}
void up(int p) {
    tree[p] = combine(tree[p * 2], tree[p * 2 + 1]);
}
void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = node();
    }
    else {
        int mid = l + r >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        up(p);
    }
}
node qry(int p, int l, int r, int ql, int qr) {
    if (l == r) return tree[p];
    else {
        int mid = l + r >> 1;
        node ans = node();
        if (ql <= mid)  ans = combine(ans, tree[p * 2]);
        if (qr > mid) ans = combine(ans, tree[p * 2 + 1]);
    }
}
int main()
{

    return 0;
}

