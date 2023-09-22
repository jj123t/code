/*************************************************************************
	> File Name: 1847c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 22:05:10 2023
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
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = 0;
        int res = 0;
        vector<int> pfx(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pfx[i] = pfx[i - 1] ^ arr[i - 1];
        }
        int j = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, pfx[i]);
            while (j < i and (pfx[i] ^ arr[j]) > pfx[i]) {
                pfx[i] ^= arr[j++];
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}
