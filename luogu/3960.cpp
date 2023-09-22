/*************************************************************************
	> File Name: 3960.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 20:33:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int>;
        vector<P> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        sort(a.begin() + 1, a.end(), [&](P x, P y) {
             int da, db;

             if (x.first == x.second) da = 0;
             else if (x.first > x.second) da = 1;
             else da = -1;

             if (y.first == y.second) db = 0;
             else if (y.first > y.second) db = 1;
             else db = -1;

             if (da != db) return da < db;
             if (da <= 0) return x.first < y.first;
             else return x.second > y.second;

             });
        int c = 0;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += a[i].first;
            c = max(c, s) + a[i].second;
        }
        cout << c << "\n";
    }
    return 0;
}

