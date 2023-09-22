/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 03:53:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    map<char, bool> mp;
    mp['a'] = true; mp['t'] = true;
    mp['c'] = true; mp['o'] = true;
    mp['d'] = true; mp['e'] = true;
    mp['r'] = true;
    string s; cin >> s;
    string t; cin >> t;
    int n = s.size();
    int idx1 = 0, idx2 = 0;
    vector<int> a(26, 0);
    vector<int> b(26, 0);
    for (auto c : s) {
        if (c != '@') a[c - 'a']++;
        else idx1++;
    }
    for (auto c : t) {
        if (c != '@') b[c - 'a']++;
        else idx2++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] == b[i]) continue;
        else {
            if (a[i] > b[i]) {
                if (mp[char('a' + i)]) {
                    if (idx2 >= a[i] - b[i]) {
                        idx2 -= a[i] - b[i];
                    }
                    else {
                        cout << "No\n";
                        return 0;
                    }
                }
                else {
                    cout << "No\n";
                    return 0;
                }
            } 
            else {
                if (mp[char('a' + i)]) {
                    if (idx1 >= b[i] - a[i]) {
                        idx1 -= b[i] - a[i];
                    }
                    else {
                        cout << "No\n";
                        return 0;
                    }
                }
                else {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    if (idx1 != idx2) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}

