/*************************************************************************
	> File Name: 1063.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 12:07:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[2000][2000];
signed main()
{
    int n; cin >> n;
    vector<int> arr(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; arr[i + n] = arr[i];
    }
    int ans = 0;
    for (int i = 2; i < 2 * n; i++) {
        for (int j = i - 1; i - j < n and j >= 1; j--) {
            for (int k = j; k < i; k++) {
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + arr[j] * arr[k + 1] * arr[i + 1]);
                ans = max(ans, dp[j][i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

