/*************************************************************************
	> File Name: 1731c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 11:32:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    vector<int> res;
    while (tt--) {
        int n; cin >> n;
        int ans = (n + 1) * n / 2;
        vector<int> mp(2 * n + 10); mp[0]++;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            tmp ^= x;
            for (int j = 0; j * j < 2 * n + 10; j++) {
                if (((j * j) ^ tmp) < 2 * n + 10)
                ans -= mp[(j * j) ^ tmp];
            }
            mp[tmp]++;
        }
        cout << ans << "\n";
    }
    return 0;
}

