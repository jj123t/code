/*************************************************************************
	> File Name: 1856c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 22:00:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int left = 0, right = 1e9;
        auto check = [&](int mid) -> bool {
            for (int i = 1; i < n; i++) {
                int j = i;
                int res = k;
                int last = 0;
                bool flag = true;
                for (j = i; j < n; j++) {
                    if (arr[j] >= mid) return true;
                    res -= mid - arr[j]; 
                    if (res < 0) flag = false;
                    mid--;
                }
                if (!flag) continue;
                if (mid <= arr[j + 1]) return true; 
            }
            return false;
        };
        cout << check(5) << "\n";
        /*
        while (left <= right) {
            int mid = left + right >> 1;
            if (check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        cout << left <<  " " << right << "\n";
        */
    }
    return 0;
}

