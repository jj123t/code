/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 22 Apr 2023 07:52:21 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    string s; cin >> s;
    bool flag1 = false, flag2 = false, flag3 = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') flag1 = true;
        if (flag1 && s[i] == '*') flag2 = true;
        if (flag2 && s[i] == '|') flag3 = true;
    }
    if (flag1 && flag2 && flag3) {
        cout << "in";
    }
    else {
        cout << "out";
    }
    return 0;
}
