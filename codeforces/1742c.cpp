/*************************************************************************
	> File Name: 1742c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 03:25:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n = 8;
        vector<string> s(8);
        for (auto &x : s) cin >> x;
        char ans = 'R';
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int j = 0; j < 8; j++) {
                if (s[i][j] == 'R') res++;
            }
            if (res == 8) ans = 'R';
        }
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int j = 0; j < 8; j++) {
                if (s[j][i] == 'B') res++;
            }
            if (res == 8) ans = 'B';
        }
        cout << ans << "\n";
    }
    return 0;
}

