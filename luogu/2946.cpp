/*************************************************************************
	> File Name: 2946.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 20:17:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, f; cin >> n >> f;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(f + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][arr[i] % f] = 1, arr[i] %= f;
    const int p = 1e8;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= f - 1; j++) {
            dp[i][j] = dp[i][j] + (dp[i - 1][(j - arr[i] + f) % f] + dp[i - 1][j] % p) % p;
        }
    }
    cout << dp[n][0] % p;
    return 0;
}

