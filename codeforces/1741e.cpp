/*************************************************************************
	> File Name: 1741e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 02:53:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i]; 
        vector<bool> dp(n + 1, false); 
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            int left = i - arr[i] - 1;
            int right = i + arr[i];
            if (left >= 0)
            dp[i] = dp[i] | dp[left];
            if (right <= n)
            dp[right] = dp[right] | dp[i - 1];
        }
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
    return 0;
}

