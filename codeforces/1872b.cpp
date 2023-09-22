/*************************************************************************
	> File Name: 1872b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep  7 22:18:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        const int INF = 1e9;
        vector<int> res(10000, INF);
        for (int i = 1; i <= n; i++) {
            int d, s; cin >> d >> s;
            res[d] = min(res[d], s);
        }
        int lim = 1e9;
        int i = 0;
        int ans = 0;
        for (i = 1; i <= 100000; i++) {
            if (i > lim) break;
            if (res[i] != INF) {
                lim = min(i + (res[i] - 1) / 2, lim);
            }
            ans = max(ans, i);
        }
        cout << ans << "\n";
    }
    return 0;
}

