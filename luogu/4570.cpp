/*************************************************************************
	> File Name: 4570.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 15:32:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(a.rbegin(), a.rend());
    vector<int> f(70);
    auto check = [&](int x) -> bool {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                if (!f[i]) {
                    f[i] = x;
                    return true;
                }
                else {
                    x ^= f[i];
                }
            }
        }
        return false;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (check(a[i].second)) ans += a[i].first; 
    }
    cout << ans << "\n";
    return 0;
}

