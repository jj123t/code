/*************************************************************************
	> File Name: 1748b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 03:20:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(10, 0);
            int cur = 0, mx = 0;
            for (int j = i; j < min(i + 100ll, n); j++) {
                cnt[s[j] - '0']++;
                if (cnt[s[j] - '0'] == 1) cur++;
                mx = max(mx, cnt[s[j] - '0']);
                if (cur >= mx) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

