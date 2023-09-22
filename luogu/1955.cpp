/*************************************************************************
	> File Name: 1955.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 15:47:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> par(N * 2);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
unordered_map<int, int> mp;
int cnt = 1;
int get(int x) {
    if (!mp.count(x)) mp[x] = ++cnt;
    return mp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        bool flag = true;
        vector<array<int, 3>> qry(n);
        for (int i = 0; i < n; i++) {
            cin >> qry[i][1] >> qry[i][2] >> qry[i][0];
            get(qry[i][1]); get(qry[i][2]);
        }
        init(cnt + 1);
        sort(qry.rbegin(), qry.rend());
        for (int i = 0; i < n; i++) {
            auto [t, a, b] = qry[i];
            a = get(a); b = get(b);
            if (t == 1) {
                if (!same(a, b)) Unite(a, b);
            }
            else {
                if (same(a, b)) { flag = false; break; }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

