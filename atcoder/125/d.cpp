/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 06:34:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) f++;
    }
    if (f & 1) {
        int x = 1e9 + 7;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(arr[i]);
            x = min(x, abs(arr[i]));
        }
        cout << sum - 2 * x;
    }
    else {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(arr[i]);
        }
        cout << sum;
    }
    return 0;
}

