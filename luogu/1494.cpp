/*************************************************************************
	> File Name: 1494.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  9 08:53:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
int tot, cnt[N];
void add(int x) {
    tot += cnt[x] * 2 + 1, cnt[x]++;
}
void del(int x) {
    tot += 1 - cnt[x] * 2, cnt[x]--;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    using P = pair<int, int>;
    vector<P> ans(m + 1);
    int len = sqrt(n);
    vector<int> arr(n + 1), bid(n + 1);
    for (int i = 1; i <= n; i++) { cin >> arr[i]; bid[i] = (i - 1) / len + 1; }
    vector<array<int, 3>> qry(m);
    for (int i = 0; i < m; i++) { cin >> qry[i][0] >> qry[i][1]; qry[i][2] = i + 1; } 
    sort(qry.begin(), qry.end(), [&](array<int, 3> a, array<int, 3> b) {
         if (bid[a[0]] == bid[b[0]]) { if (bid[a[0]] & 1) return a[1] < b[1]; else return a[1] > b[1]; }
         else { return bid[a[0]] < bid[b[0]]; } });
    auto [l, r, id] = qry[0];
    len = r - l + 1;

    for (int i = l; i <= r; i++) add(arr[i]);
    if (tot != len) {
        int d = gcd(tot - len, len * (len - 1));
        ans[id] = {(tot - len) / d, len * (len - 1) / d};
    }

    for (int i = 1; i < m; i++) {
        auto [L, R, tid] = qry[i];  
        id = tid;
        len = R - L + 1;
        while (l < L) del(arr[l++]);
        while (l > L) add(arr[--l]);
        while (r > R) del(arr[r--]);
        while (r < R) add(arr[++r]);
        if (tot != len) {
            int d = gcd(tot - len, len * (len - 1));
            ans[id] = {(tot - len) / d, len * (len - 1) / d};
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i] == P(0, 0)) cout << "0/1\n"; 
        else cout << ans[i].first <<  "/" << ans[i].second << "\n";
    }
    return 0;
}

