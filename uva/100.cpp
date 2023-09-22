/*************************************************************************
	> File Name: 100.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep  4 19:12:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    vector<int> res(10010);
    for (int i = 1; i <= 10000; i++) {
        int x = i;
        int t = 0;
        while (x != 1) {
            if (x & 1) x = x * 3 + 1;
            else x /= 2;
            t++;
        }
        res[i] = t;
    }
    int n, m;
    while (cin >> n >> m) {
        if (n > m) swap(n, m);
        int mx = 0;
        for (int i = n; i <= m; i++) {
            mx = max(mx, res[i]);
        }
        cout << n << " " << m << " " << mx << '\n';
    }
    return 0;
}

