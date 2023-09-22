/*************************************************************************
	> File Name: 1747a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 19:35:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ans += x;
        }
        cout << abs(ans) << "\n";
    }
    return 0;
}

