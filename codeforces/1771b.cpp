/*************************************************************************
	> File Name: 1771b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jun 27 23:00:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        set<int> q[n + 1];
        for (int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            q[l].insert(r);
            q[r].insert(l);
        }
        int j = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            while (j <= n) {
                auto it = q[j].lower_bound(i);
                if (it == q[j].end()) {
                    j++;
                    continue;
                }
                if ((*it) >= i && (*it) <= j) {
                    break;
                }
                else {
                    j++;
                }
            }
            ans += j - i;
        }
        cout << ans << "\n";
    }
    return 0;
}

