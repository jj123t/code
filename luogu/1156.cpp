/*************************************************************************
	> File Name: 1156.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 19:19:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d, g; cin >> d >> g;
    vector<array<int, 3>> arr(g + 1);
    for (int i = 1; i <= g; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin(), arr.end());
    vector<int> dp(d + 1);
    dp[0] = 10;
    for (int i = 1; i <= g; i++) {
        for (int j = d; j >= 0; j--) {
            if (dp[j] >= arr[i][0]) {
                if (j + arr[i][2] >= d) {
                    cout << arr[i][0];
                    return 0;
                }
                dp[j + arr[i][2]] = max(dp[j + arr[i][2]], dp[j]);
                dp[j] += arr[i][1];
            }
        }
    }
    cout << dp[0];
    return 0;
}

