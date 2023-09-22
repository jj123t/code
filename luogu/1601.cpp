/*************************************************************************
	> File Name: 1601.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 04:05:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int flag = 0;
    int i = 0;
    string s = "";
    while (i < a.size() && i < b.size()) {
        s += (char)('0' + (flag + (a[i] - '0') + (b[i] - '0')) % 10);
        flag = (flag + (a[i] - '0') + (b[i] - '0')) / 10;
        i++;
    }
    while (i < a.size()) {
        s += (char)('0' + (flag + (a[i] - '0')) % 10);
        flag = (a[i] - '0' + flag) / 10;
        i++;
    }
    while (i < b.size()) {
        s += (char)('0' + (flag + (b[i] - '0')) % 10);
        flag = (b[i] - '0' + flag) / 10;
        i++;
    }
    while (flag) {
        s += (char)('0' + flag % 10);
        flag /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}

