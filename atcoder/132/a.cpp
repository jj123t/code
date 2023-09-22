/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:45:11 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    map<char, int> mp;
    string s; cin >> s;
    for (auto c : s) mp[c]++;
    bool flag = true;
    for (auto c : mp) if (c.second != 2) flag = false;
    cout << (mp.size() == 2 && flag ? "Yes" : "No");
    return 0;
}
