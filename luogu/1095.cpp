/*************************************************************************
	> File Name: 1095.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 21:26:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, s, t; cin >> m >> s >> t;
    vector<int> dp(t + 1);
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; i++) {
        if (dp[i] < dp[i - 1] + 17) dp[i] = dp[i - 1] + 17;
        if (dp[i] >= s) {
            cout << "Yes\n" << i << "\n";
            return 0;
        }
    }
    cout << "No\n" << dp[t] << "\n";
    return 0;
}

