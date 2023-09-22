/*************************************************************************
	> File Name: 1775a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 10 20:07:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        {
            bool flag = true;
            if (s[0] == 'a' and s.back() == 'b') {
                int idx = 0;
                while (s[idx] != 'b') idx++;
                if (idx == n - 1) cout << s.substr(0, n - 2) << " " << s[n - 2] << " " << s[n - 1] << "\n";
                else {
                    cout << s.substr(0, idx) << " " << s.substr(idx, n - 1 - idx) << " " << s[n - 1] << "\n";
                }
            }
            else if (s[0] == 'a' and s.back() == 'a') {
                string s2 = "";
                for (int i = 1; i < n -1; i++) s2 += s[i];
                cout << s[0] << " " << s2 << " " << s.back() << "\n";
            }
            else if (s[0] == 'b' and s.back() == 'b') {
                string s2 = "";
                for (int i = 1; i < n -1; i++) s2 += s[i];
                cout << s[0] << " " << s2 << " " << s.back() << "\n";
            }
            else {
                if (s[1] == 'b') {
                    string s2 = "";
                    for (int i = 1; i < n - 1; i++) s2 += s[i];
                    cout << s[0] <<  " " << s2 << " " << s.back() << "\n";
                }
                else {
                    cout << s[0] << " " << s[1] << " " << s.substr(2, n - 2) << "\n";
                }
            }
        }
    }
    return 0;
}

