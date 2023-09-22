/*************************************************************************
	> File Name: 1048.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 16:24:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, m; cin >> t >> m;
    vector<int> ct(m + 1), w(m + 1);
    for (int i = 1; i <= m; i++) cin >> ct[i] >> w[i];
    vector<int> dp(t + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = t; j - ct[i] >= 0; j--) {
            dp[j] = max(dp[j], dp[j - ct[i]] + w[i]); 
        }
    }
    cout << dp[t];
    return 0;
}

