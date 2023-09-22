/*************************************************************************
	> File Name: 1853a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 22:25:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        int ans = 1e9;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            if (arr[i] < arr[i - 1])  flag = false;
            else if (arr[i] == arr[i - 1]) {
                ans = min(ans, 1);
            }
            else {
                int d = arr[i] - arr[i - 1];
                if (d % 2 == 0) ans = min(ans, d / 2 + 1);
                else ans = min(ans, (d + 1) / 2);
            }
        }
        if (!flag) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}

