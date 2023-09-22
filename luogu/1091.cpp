/*************************************************************************
	> File Name: 1091.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 21:00:16 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> dp1(n + 1), dp2(n + 1);
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = n; j >= 1; j--) {
            if (arr[j] < arr[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << n - ans << "\n";
    return 0;
}

