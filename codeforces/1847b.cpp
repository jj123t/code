/*************************************************************************
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 22:05:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)  cin >> arr[i];
        int ans = 0;
        vector<int> vis(30, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if (arr[i] >> j & 1) ;
                else vis[j] = true;
            }
            bool flag = true;
            for (int j = 0; j < 30; j++) {
                if (!vis[j]) flag = false;
            }
            if (flag) ans++, fill(vis.begin(), vis.end(), false);
        }
        ans = max(1ll, ans);
        cout << ans << "\n";
    }
    return 0;
}

