/*************************************************************************
	> File Name: 1742.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 03:21:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            ans += x;
            mp[x]++;
        }
        if (ans % 2 == 0 && mp[ans / 2]) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}

