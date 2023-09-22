/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 18:17:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string s; cin >> s;
    vector<string> t;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - i);
        string res = b + a;
        t.push_back(res);
    }
    sort(t.begin(), t.end());
    cout << t[0] << " " << t.back();
    return 0;
}

