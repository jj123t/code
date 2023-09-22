/*************************************************************************
	> File Name: 1828c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 16:41:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) cin >> brr[i];
        sort(arr.begin(), arr.end());
        sort(brr.rbegin(), brr.rend());
        int ans = 1;
        bool flag = true;
        const int p = 1e9 + 7;
        // 2 4 5 6 8 9
        // 1 1 3 4 5 6
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(arr.begin(), arr.end(), brr[i]) - arr.begin();
            if (it == n) flag = false;
            int d = n - it - i;
            ans = ans * d % p;
        }
        if (flag) cout << ans << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}

