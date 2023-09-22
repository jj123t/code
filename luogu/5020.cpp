/*************************************************************************
	> File Name: 5020.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 19 13:41:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr.begin() + 1, arr.end());
        vector<int> dp(arr.back() + 1, 0);
        int ans = n;
        for (int i = 1; i <= n; i++) {
            int x = arr[i];
            if (dp[x]) ans--;
            dp[x] = true;
            for (int k = x; k <= arr.back(); k++) {
                dp[k] |= dp[k - x];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

