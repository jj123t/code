/*************************************************************************
	> File Name: 1030.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 21:24:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string a, b;
string dfs(string s, string t) {
    if (s.size() == 1 or s.size() == 0) return s;
    char c = t.back();
    int i;
    map<char, bool> mp;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == c) break;
        mp[s[i]] = true;
    }
    string s1 = "", s2 = "";
    for (int j = 0; j < s.size(); j++) {
        if (j == i) continue;
        if (mp[s[j]]) s1 += s[j];
        else s2 += s[j];
    }
    string t1 = "", t2 = "";
    for (int j = 0; j < t.size() - 1; j++) {
        if (mp[t[j]]) t1 += t[j];
        else t2 += t[j];
    }
    return t.back() + dfs(s1, t1) + dfs(s2, t2); 
}
int main()
{
    cin >> a >> b;
    cout << dfs(a, b);
    return 0;
}

