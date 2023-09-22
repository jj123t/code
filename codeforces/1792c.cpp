/*************************************************************************
	> File Name: 1792c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 19:51:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1); 
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int left = 0, right = n / 2;
        auto check = [&] (int l, int r) {
            int res = l;
            for (int i = 1; i <= n; i++) {
                if (arr[i] >= l && arr[i] <= r) {
                    if (arr[i] != res) return false;
                    res++;
                }
            }
            return true;
        };
        while (left <= right) {
            int mid = left + right >> 1;
            if (check(mid + 1, n - mid)) right = mid - 1;
            else left = mid + 1;
        }
        cout << left << '\n';
    }
    return 0;
}

