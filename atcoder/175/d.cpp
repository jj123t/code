/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun  1 06:18:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n), prr(n);
    for (auto &x : arr) cin >> x;
    for (auto &x : prr) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> vis(n, false);
        vector<int> s(n + 1, 0);

    }
    cout << ans;
    return 0;
}

