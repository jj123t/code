/*************************************************************************
	> File Name: 1794a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 22:02:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> s(2 * n - 2);
        for (auto &x : s) cin >> x;
        sort(s.begin(), s.end(), [&](string a, string b) {return a.size() > b.size(); });
        string resa = s[0] + s[1].back();
        string resb = s[1] + s[0].back();
        string t;
        if (resa.substr(1, s[0].size()) == s[1]) t = resa;  
        if (resb.substr(1, s[1].size()) == s[0]) t = resb; 
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (t[i] != t[n - 1 - i]) flag = false;
        }
        if (flag) cout << "YES\n";
        else cout << "No\n";
    }
    return 0;
}

