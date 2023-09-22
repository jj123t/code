/*************************************************************************
	> File Name: 1759a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:23:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        bool flag = true;
        for (auto c : s) {
            if (c != 'Y' && c != 'e' && c != 's') {
                flag = false;
            }
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == 'Y') {
                if (s[i - 1] != 's') {
                    flag = false;
                }
            }
            else if (s[i] == 'e') {
                if (s[i - 1] != 'Y') {
                    flag = false;
                }
            }
            else { 
                if (s[i - 1] != 'e') {
                    flag = false;
                }
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}

