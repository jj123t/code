/*************************************************************************
  > File Name: 10170.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Mon Sep 18 13:08:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int a, b;
    while (cin >> a >> b) {
        int left = 0, right = 1e9;
        auto check = [&](int mid) -> int {
            int A = a * (mid + 1);
            int B = (0 + mid) * (mid + 1) / 2;
            return A + B;
        };
        while (left <= right) {
            int mid = left + right >> 1;
            if (check(mid) >= b) right = mid - 1;
            else left = mid + 1;
        }
        cout << left + a << "\n";
    }
    return 0;
}

