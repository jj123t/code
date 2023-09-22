/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat May 13 18:37:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    string s = to_string(n);
    while (s.size() < 4) s = "0" + s;
    cout << s;
    return 0;
}

