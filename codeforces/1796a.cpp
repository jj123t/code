/*************************************************************************
	> File Name: 1796a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 22:05:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    string t = "";
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 and i % 5 == 0) {
            t += "FB";
        }
        else if (i % 3 == 0) {
            t += "F";
        }
        else if (i % 5 == 0) {
            t += "B";
        }
    }
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        bool flag = false;
        for (int i = 0; i < t.size() - n; i++) {
            if (t.substr(i, n) == s) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

