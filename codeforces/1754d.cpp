/*************************************************************************
	> File Name: 1754d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 04:54:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    for (int i = 1; i < k; i++) {
        if (mp[i] % (i + 1) == 0) {
            mp[i + 1] += mp[i] / (i + 1);
            mp[i] = 0;
        }
    }
    bool flag = true;
    for (int i = 1; i < k; i++) {
        if (mp[i]) flag = false;
    }
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}

