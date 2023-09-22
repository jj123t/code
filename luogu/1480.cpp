/*************************************************************************
	> File Name: 1480.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 05:32:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    string a; int b; cin >> a >> b;
    string ans = "";
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += (char)((d * 10 + a[i] - '0') / b + '0');
        d = (d * 10 + a[i] - '0') % b;
    }
    bool up = false;
    for (int i = 0; i < ans.size(); i++) {
        if (!up && ans[i] == '0') {
            continue;
        }
        else {
            up = true;
            cout << ans[i];
        }
    }
    if (!up) cout << 0;
    return 0;
}

