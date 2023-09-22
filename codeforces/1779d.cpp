/*************************************************************************
	> File Name: 1779d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 10 19:28:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) cin >> brr[i];
        vector<vector<int>> st(n + 100, vector<int>(log2(n) + 1, 0));
        for (int i = 1; i <= n; i++) st[i][0] = brr[i - 1];
        for (int j = 1; j <= log2(n); j++) {
            for (int i = 1; i + (1 << (j - 1)) - 1 <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto get = [&](int l, int r) {
            int x = log2(r - l + 1);
            return max(st[l][x], st[r - (1 << x) + 1][x]);
        };
        int m; cin >> m;
        map<int, int> mp;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            mp[x]++;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) if (arr[i] < brr[i]) { flag = false; break; }
        if (!flag) { cout << "NO\n"; continue; }
        map<int, vector<int>> vt;
        for (int i = 0; i < n; i++) {
            if (arr[i] == brr[i]) continue;
            vt[brr[i]].push_back(i);
        }
        for (auto [t, v] : vt) {
            /*
            cout << t << '\n';
            for (auto x : v) cout << x << " --- ";
            cout << "\n";
            */
            int nm = v.size();
            int res = 1;
            for (int i = 0; i < nm - 1; i++) {
                int a = v[i], b = v[i + 1];
                a++, b++;
                if (get(a, b) > t) {
                    res++;
                }
            }
            //cout << res << " ??? " << mp[t] << "\n";
            if (res > mp[t]) { flag = false; break; }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

