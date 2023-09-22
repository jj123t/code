/*************************************************************************
	> File Name: ee.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 02:00:51 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 4e6 + 10;
vector<vector<int>> tree(N, vector<int>(26, 0));
int n;
void add(int i, int x, int v) {
    if (i == 0) return ;
    while (i <= n) {
        tree[i][x] += v;
        i += (i & -i);
    }
}
int qry(int i, int x) {
    int res = 0;
    while (i > 0) {
        res += tree[i][x];
        i -= (i & -i);
    }
    return res;
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        add(i + 1, s[i] - 'a', 1);
    }
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; char c; cin >> x >> c;
            int v = c - 'a';
            int t = s[x - 1] - 'a';
            s[x - 1] = c;
            add(x, t, -1);
            add(x, v, 1);
        }
        else {
            int l, r; cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                if (qry(r, i) - qry(l - 1, i) > 0) {
                    ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
