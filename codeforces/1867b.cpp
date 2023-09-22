/*************************************************************************
	> File Name: 1867b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 22:09:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int d = 0;
        int dis = 0, like = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[n - 1 - i] != s[i]) {
                dis++;
            }
            else if (s[i] == '1') {
                like++;
            }
        }
        // << " " << like << '\n';
        string ans = "";
        for (int i = 0; i <= n; i++) {
            bool ok = false;
            if (i >= dis) {
                if ((i - dis) % 2 == 0 and (i - dis) <= (n - dis * 2)) {
                    ok = true;
                }
                else {
                    if (n & 1 and (i - dis) <= (n - dis * 2)) {
                        ok = true;
                    }
                    else {
                        ok = false;
                    }
                }
            }
            if (ok) {
                ans += "1";
            }
            else {
                ans += "0";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

