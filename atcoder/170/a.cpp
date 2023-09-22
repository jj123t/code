/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 15 Apr 2023 08:22:10 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    for (auto c : s) {
        if (c == 'o') {
            flag = true;
        }
        if (c == 'x') {
            cout << "No\n";
            return 0;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
