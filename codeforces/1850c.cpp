/*************************************************************************
	> File Name: 1850c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 22:41:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt ;cin >> tt;
    while (tt--) {
        int n = 8;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (j = 0; j < n; j++) {
                if (s[i][j] != '.') break;
            }
            int idx = i;
            while (j < n and idx < n && s[idx][j] != '.') {
                res += s[idx][j];
                idx++;
            }
            if (res != "") break;
        }
        cout << res << "\n";
    }
    return 0;
}

