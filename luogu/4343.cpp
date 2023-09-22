/*************************************************************************
	> File Name: 4343.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 00:39:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x; 
    auto check = [&](int mid) {
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += arr[i];
            if (tmp >= mid) {
                tmp = 0;
                res++;
            }
            if (tmp < 0) tmp = 0;
        }
        return res;
    };
    int A, B;
    int left = 1, right = 1e18;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid) <= k) right = mid - 1;
        else left = mid + 1;
    } 
    A = (check(left) == k ? left : -1);

    left = 1, right = 1e18;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid) >= k) left = mid + 1;
        else right = mid - 1;
    }
    B = right;

    if (A == -1) {
        cout << -1;
    }
    else 
        cout << A << " " << B << "\n";
    return 0;
}
