/*************************************************************************
	> File Name: 1736.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 22 06:27:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        vector<int> b(n + 1); b[0] = a[0];
        for (int i = 0; i < n - 1; i++) {
            b[i + 1] = lcm(a[i], a[i + 1]);
        }
        b[n] = a[n - 1];
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (gcd(b[i], b[i - 1]) != a[i - 1]) {
                flag = false;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}

