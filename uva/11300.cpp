/*************************************************************************
	> File Name: 11300.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 16:51:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n; 
    while (cin >> n) {
        vector<int> a(n + 1);
        int s = 0;
        for (int i = 1; i <= n; i++) { cin >> a[i]; s += a[i]; }
        s /= n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) { p[i] = p[i - 1] + a[i] - s; }
        sort(p.begin() + 1, p.end());
        int c = p[(n + 1) / 2];
        int ans = 0;
        for (int i = 1; i <= n; i++) { ans += abs(c - p[i]); }
        cout << ans << "\n";
    }
    return 0;
}

