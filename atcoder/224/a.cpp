/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 28 01:43:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string s; cin >> s;
    int n = s.size();
    if (s[n - 1] == 'r' && s[n - 2] == 'e') {
        cout << "er";
    }
    else {
        cout << "ist";
    }
    return 0;
}

