/*************************************************************************
	> File Name: 1060.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 20 14:35:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> m >> n;
    using P = pair<int, int>;
    vector<P> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= arr[i].first; j--) {
            dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].first * arr[i].second);
        }
    }
    cout << dp[m];
    return 0;
}

