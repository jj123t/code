/*************************************************************************
	> File Name: 2801.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 14:52:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 10;
vector<int> arr(N);
vector<int> id(N);
vector<int> lz(N);
vector<int> st(N, 1e9);
vector<int> ed(N, -1e9);
vector<int> t(N);
void sort(int idi) {
    for (int i = st[idi]; i <= ed[idi]; i++) t[i] = arr[i];
    sort(t.begin() + st[idi], t.begin() + ed[idi] + 1);
}
void add(int l, int r, int val) {
    int sid = id[l], eid = id[r];
    if (sid == eid) {
        for (int i = l; i <= r; i++) arr[i] += val;
        sort(sid);
        return ;
    } 
    for (int i = l; id[i] == sid; i++) arr[i] += val; 
    sort(sid);
    for (int i = sid + 1; i < eid; i++) lz[i] += val;

    for (int i = r; id[i] == eid; i--) arr[i] += val; 
    sort(eid);
}
int qry(int l, int r, int val) {
    int sid = id[l], eid = id[r];
    int ans = 0;
    if (sid == eid) {
        for (int i = l; i <= r; i++) if (arr[i] + lz[sid] >= val) ans++;
        return ans;
    }
    for (int i = l; id[i] == sid; i++) if (arr[i] + lz[sid] >= val) ans++;
    for (int i = sid + 1; i < eid; i++) {
        auto it = lower_bound(t.begin() + st[i], t.begin() + ed[i] + 1, val - lz[i]) - t.begin();
        int d = ed[i] - it + 1;
        ans += d;
    }
    for (int i = r; id[i] == eid; i--) if (arr[i] + lz[eid] >= val) ans++;
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    int len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        id[i] = (i - 1) / len + 1;
        st[id[i]] = min(st[id[i]], i);
        ed[id[i]] = max(ed[id[i]], i);
    }
    t = arr;
    for (int i = id[1]; i < id[n]; i++) {
        sort(t.begin() + st[i], t.begin() + ed[i] + 1);
    }
    for (int i = 1; i <= q; i++) {
        char opt; cin >> opt;
        if (opt == 'M') {
            int l, r, w; cin >> l >> r >> w;
            add(l, r, w);
        }
        else {
            int l, r, c; cin >> l >> r >> c;
            cout << qry(l, r, c) << "\n";
        }
    }
    return 0;
}

