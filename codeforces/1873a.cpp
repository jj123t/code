/*************************************************************************
	> File Name: 1873a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 22:32:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        if (s == "abc" or s == "acb" or s == "bac" or s == "cba") cout << "YEs\n";
        else cout << "No\n";
    }
    return 0;
}

