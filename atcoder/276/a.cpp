/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 03:16:41 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    string s; cin >> s;
    int n = s.size();
    for (int i = n - 1; i > -1; i--) {
        if (s[i] == 'a') {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
