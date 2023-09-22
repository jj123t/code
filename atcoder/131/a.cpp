/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:59:25 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    string s; cin >> s;
    int n = s.size();
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            flag = true;
        }
    }
    cout << (flag ? "Bad" : "Good");
    return 0;
}
