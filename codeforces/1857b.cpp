/*************************************************************************
	> File Name: 1857b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 22:18:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        int idx = -1, flag = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - '0' + flag;
            if (x >= 5) {
                idx = i;
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
        if (s.back() - '0' + flag >= 5) {
            for (int i = 0;  i< s.size(); i++) s[i] = '0'; 
            s.push_back('1');
        }
        else {
            if (idx != -1) {
            for (int i = 0; i <= idx; i++) s[i] = '0';
            s[idx + 1]++;
            
        }}
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}

