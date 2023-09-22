/*************************************************************************
	> File Name: 1903.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  9 10:55:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

struct q{
    int l, r, id, pre;
}qry[N];

struct cr {
    int pos, val;
}c[N];

int bid[N], a[N], color[N], ans[N];
int cnum = 0, qnum = 0, tot = 0;

bool cmp(q &a, q &b) {
    if (bid[a.l] == bid[b.l]) {
        if (bid[a.r] == bid[b.r]) return a.pre < b.pre;
        else return a.r < b.r;
    }
    return bid[a.l] < bid[b.l];
}

void add(int x) {
    if (++color[x] == 1) tot++;
}

void del(int x) {
    if (--color[x] == 0) tot--;
}

void change(int now, int i) {
    if (c[now].pos >= qry[i].l and c[now].pos <= qry[i].r) {
        if (--color[a[c[now].pos]] == 0) tot--;
        if (++color[c[now].val] == 1) tot++;
    }
    swap(c[now].val, a[c[now].pos]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    int len = pow(n, 2.0/3) + 1;
    for (int i = 1; i <= n; i++) { cin >> a[i]; bid[i] = (i - 1) / len + 1; }
    for (int i = 0; i < m; i++) {
        char op; cin >> op;
        if (op == 'Q') {
            cin >> qry[++qnum].l;
            cin >> qry[qnum].r;
            qry[qnum].id = qnum;
            qry[qnum].pre = cnum;
        }
        else {
            cin >> c[++cnum].pos;
            cin >> c[cnum].val;
        }
    }
    sort(qry + 1, qry + qnum + 1, cmp);
    int l = 1, r = 0, t = 0; 
    for (int i = 1; i <= qnum; i++) {
        while (l < qry[i].l) del(a[l++]);
        while (l > qry[i].l) add(a[--l]);

        while (r < qry[i].r) add(a[++r]);
        while (r > qry[i].r) del(a[r--]);

        while (t < qry[i].pre) change(++t, i);
        while (t > qry[i].pre) change(t--, i);

        ans[qry[i].id] = tot;
    }
    for (int i = 1; i <= qnum; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}


