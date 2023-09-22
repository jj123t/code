/*************************************************************************
	> File Name: 1736c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 22 22:26:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int j = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && arr[j] - (j - i + 1) >= 0) {
                j++;
            }
            ans += (j - i);
        }
        cout << ans << "\n";
    }
    return 0;
}

