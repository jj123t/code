/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 03:53:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;
    for (auto c : s) {
        if (c == 'T') a++;
        else b++;
    }
    if (a >= b) cout << "T";
    else cout << "A";
    return 0;
}

