/*************************************************************************
	> File Name: 1796b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 22:20:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s, t; cin >> s >> t;
        if (s[0] == t[0]) {
            cout << "YES\n";
            cout << s[0] << "*" << '\n';
        }
        else if (s.back() == t.back()) {
            cout << "YES\n";
            cout << "*" << s.back() << "\n";
        }
        else {
            int n = s.size(), m = t.size();
            string res = "";
            for (int i = 0; i < n - 1; i++) {
                string r1 = s.substr(i, 2);
                bool flag = false;
                for (int j = 0; j < m - 1; j++) {
                    if (t.substr(j, 2) == r1) {
                        flag = true;
                        res = r1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (res.size() >= 2) { 
                cout << "YES\n";
                cout << "*" << res << "*" << '\n';
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

