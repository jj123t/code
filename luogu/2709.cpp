/*************************************************************************
	> File Name: 2709.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  9 13:42:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct q {
    int l, r, id;
}qry[N];
int bid[N], cnt[N], a[N], ans[N], tot = 0;
bool cmp(q &a, q &b) {
    if (bid[a.l] == bid[b.l]) {
        if (bid[a.l] & 1) return a.r < b.r;
        return a.r > b.r;
    }
    return bid[a.l] < bid[b.l];
}
void add(int x) {
    tot += 2 * cnt[x] + 1, cnt[x]++;
}
void del(int x) {
    tot += 1 - 2 * cnt[x], cnt[x]--;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int len = sqrt(k);
    for (int i = 1; i <= k; i++) bid[i] = (i - 1) / len + 1;
    for (int i = 1; i <= m; i++) { cin >> qry[i].l >> qry[i].r; qry[i].id = i; }
    sort(qry + 1, qry + m + 1, cmp);
    int l = qry[1].l, r = qry[1].r;
    for (int i = l; i <= r; i++) add(a[i]);
    ans[qry[1].id] = tot;
    for (int i = 2; i <= m; i++) {
        while (l < qry[i].l) del(a[l++]);
        while (l > qry[i].l) add(a[--l]);
        while (r < qry[i].r) add(a[++r]);
        while (r > qry[i].r) del(a[r--]);
        ans[qry[i].id] = tot;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
