/*************************************************************************
	> File Name: 1766b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 00:16:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        map<string, int> mp;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            string t = "";
            t += s[i - 1];
            t += s[i];
            if (mp[t] && i - mp[t] >= 2) flag = true;
            else if (!mp[t]) mp[t] = i;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

