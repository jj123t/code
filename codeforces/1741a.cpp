/*************************************************************************
	> File Name: 1741a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 01:16:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string a, b; cin >> a >> b;
        if (a == b) {
            cout << "=" << '\n';
            continue;
        }
        map<char, int> mp;
        mp['M'] = 0; mp['L'] = 1, mp['S'] = -1;
        if (mp[a.back()] < mp[b.back()]) {
            cout << "<" << "\n";
        }
        else if (mp[a.back()] > mp[b.back()]) {
            cout << ">" << "\n";
        }
        else {
            if (a.back() == 'L') {
                cout << (a.size() > b.size() ? ">" : "<") << '\n';
            }
            else {
                cout << (a.size() < b.size() ? ">" : "<") << "\n";
            }
        }
    }
    return 0;
}

