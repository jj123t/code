/*************************************************************************
	> File Name: 1208.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 20:05:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, int>;
    vector<P> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int res = 0;
    int j = 0;
    int ans = 0;
    while (j < m) {
        if (res + a[j].second <= n) {
            ans += a[j].first * a[j].second;
            res += a[j].second;
            j++;
        }
        else {
            ans += a[j].first * (n - res);
            res = n;
            break;
        }
    }
    cout << ans ;
    return 0;
}

