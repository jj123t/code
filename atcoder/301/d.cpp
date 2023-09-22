/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 03:53:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    string s; cin >> s;
    int n; cin >> n;
    int m = s.size();
    reverse(s.begin(), s.end());
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') {
            tmp += (1ll << i);
        }
    }
    if (tmp > n) {
        cout << -1;
        return 0;
    }
    for (int i = m - 1; i > -1; i--) {
        if (s[i] == '?') {
            int res = (1ll << i);
            if (tmp + res <= n)
                tmp += res;
        }
    }
    cout << tmp;
    return 0;
}

