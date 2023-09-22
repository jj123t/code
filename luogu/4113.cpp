/*************************************************************************
	> File Name: 4113.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 13:23:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int tree[N];
int n;
void add(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
} 
int qry(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, m; cin >> n >> c >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<array<int, 3>> q;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        q.push_back({l, r, i});
    }
    sort(q.begin(), q.end());
    vector<int> ans(n);
    vector<int> nxt(n + 1), last(c + 1);
    for (int i = n; i >= 1; i--) {
        nxt[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    for (int i = 1; i <= c; i++) {
        if (last[i] and nxt[last[i]]) {
            add(nxt[last[i]], 1);
        }
    }
    int l = 1;
    for (int i = 0; i < m; i++) {
        auto [left, right, id] = q[i];
        while (l < left) {
            if (nxt[l]) add(nxt[l], -1);
            if (nxt[l] and nxt[nxt[l]]) add(nxt[nxt[l]], 1);
            l++;
        } 
        ans[id] = qry(right) - qry(left - 1);
    }
    for (auto x : ans) cout << x << '\n';
    return 0;
}

