/*************************************************************************
	> File Name: 1867c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 22:09:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        int cnt = 0;
        for (auto c : s) {
            if (c == cnt) cnt++;
            else break;
        }
        int x = cnt;
        int y = 0;
        while (y != -1) {
            cout << x << endl;
            cin >> y;
            if (y <= cnt) {
                x = y;
            }
            else {
                cnt++;
                x = cnt;
            }
        }
    }
    return 0;
}

