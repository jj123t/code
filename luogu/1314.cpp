/*************************************************************************
	> File Name: 1314.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 18 23:21:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m, s; cin >> n >> m >> s;
    using P = pair<int, int>;
    vector<P> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<P> qry(m);
    for (int i = 0; i < m; i++) cin >> qry[i].first >> qry[i].second;
    auto check = [&](int mid) -> int {
        vector<int> pfx(n + 1);
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i - 1].first >= mid) {
                num[i] = num[i - 1] + 1;
                pfx[i] = pfx[i - 1] + a[i - 1].second;
            }
            else {
                num[i] = num[i - 1];
                pfx[i] = pfx[i - 1];
            }
        }
        int res = 0;
        for (auto [l, r] : qry) {
            res += (num[r] - num[l - 1]) * (pfx[r] - pfx[l - 1]);
        }
        return res;
    };
    int left = -1e17, right = 1e17;
    int ans = 1e18;
    while (left <= right) {
        int mid = left + right >> 1;
        int t = check(mid);
        ans = min(ans, abs(s - t));
        if (t == s) { cout << 0 << "\n"; return 0; }
        else if (t > s) left = mid + 1;
        else right = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}

