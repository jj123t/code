/*************************************************************************
	> File Name: 1850d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 22:49:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr.begin() + 1, arr.end());
        int res = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (arr[i] - arr[i - 1] > k) {
                res = 1;
            }
            else res++;
            ans = max(ans, res);
        }
        if (ans == 0) cout << 0 << "\n";
        else 
            cout << n - ans << "\n";
    }
    return 0;
}

