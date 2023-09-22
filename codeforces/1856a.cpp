/*************************************************************************
	> File Name: 1856a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 22:00:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int ans =0;
        bool flag = false;
        vector<int> pfx(n + 1);
        for (int i = 1; i <= n; i++) {
            pfx[i] = max(pfx[i - 1], arr[i]);
        }
        int idx = n;
        for (int i = n; i >= 1; i--) {
            if (arr[i] >= pfx[i]) continue;
            else {
                idx = i;
                break;
            }
        }
        for (int i = 2; i <= idx; i++) {
            if (arr[i] < arr[i - 1]) {
                flag = true;
            }
        }
        if (flag) {
            for (int i = 1; i <= idx; i++) {
                ans = max(ans, arr[i]);
            }
        }
        else {
            ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}

