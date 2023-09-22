/*************************************************************************
	> File Name: 1743d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 19:02:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    {
        int a = 0;
        while (a < n && s[a] == '0') a++;
        if (a == n) {
            cout << 0 ;
            return 0;
        }
        string t = "";
        for (int i = a; i < n; i++) {
            t += s[i];
        }
        s = t;
        n = s.size();
    }
    int idx;
    {
        int a = 0;
        while (a < s.size() && s[a] == '1') a++;
        idx = a;
    }
    string ans = s;
    int d = n - idx;
    for (int i = 0; i < idx; i++) {
        string t = s.substr(i, d);
        string res = s; 
        for (int j = 0; j < d; j++) {
            if (t[j] == '1') {
                res[idx + j] = '1';
            }
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}

