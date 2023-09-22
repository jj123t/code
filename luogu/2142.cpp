/*************************************************************************
	> File Name: 2142.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 04:26:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string a, b; cin >> a >> b;
    if (a == b) {
        cout << 0;
        return 0;
    }
    bool inv = 0;
    if (b.size() > a.size()) {
        inv = true;
        swap(a, b);
    }
    else if (a.size() > b.size()) {
        ;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) continue;
            if (a[i] < b[i]) {
                inv = true;
                swap(a, b);
                break;
            }
            else {
                break;
            }
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int flag = 0;
    int i = 0;
    string s = "";
    while (i < a.size() && i < b.size()) {
        int x = ((a[i] - '0') - (b[i] - '0')) - flag;
        if (x >= 0) {
            s += (char)('0' + x);
            flag = 0;
        }
        else {
            s += (char)('0' + 10 + x);
            flag = 1;
        }
        i++;
    }
    while (i < a.size()) {
        int x = (a[i] - '0' - flag);
        if (x >= 0) {
            s += (char)('0' + x);
            flag = 0;
        }
        else {
            s += (char)('0' + 10 + x);
            flag = 1;
        }
        i++;
    }
    while (i < b.size()) {
        int x = (-(b[i] - '0') - flag);
        if (x >= 0) {
            s += (char)('0' + x);
            flag = 0;
        }
        else {
            s += (char)('0' + 10 + x);
            flag = 1;
        }
        i++;
    }
    reverse(s.begin(), s.end());
    if (inv) cout << "-";
    bool go = false;
    for (int i = 0; i < s.size(); i++) {
        if (!go && s[i] == '0') {
            continue;
        }
        else {
            go = true;
            cout << s[i];
        }
    }
    return 0;
}
 
