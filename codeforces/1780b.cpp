/*************************************************************************
	> File Name: 1780b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 19:41:58 2023
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
        int s = 0;
        for (int i = 0; i < n; i++) s += arr[i];
        int t = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            t += arr[i];
            ans = max(ans, gcd(t, s - t));
        }
        cout << ans << "\n";
    }
    return 0;
}

