/*************************************************************************
	> File Name: p2678.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 06:52:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int l, n, m; cin >> l >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    arr.push_back(l);
    sort(arr.begin(), arr.end());
    n++;
    int left = 0, right = l;
    auto check = [&](int mid) {
        int ans = 0;
        int res = 0;
        int tmp = 0;
        while (res < n) {
            while (res < n && arr[res] - tmp < mid) {
                res++;
                ans++;
            }
            tmp = arr[res++];
        }
        return ans <= m;
    };
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << left - 1 << "\n";
    return 0;
}

