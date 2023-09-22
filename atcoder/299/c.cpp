/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 22 Apr 2023 07:52:28 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int pos = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            pos++;
        }
        else {
            ans = max(ans, pos);
            flag = false;
            pos = 0;
        }
    }
    if (!flag) ans = max(ans, pos);
    else {
        cout << -1;
        return 0;
    }
    if (ans) cout << ans;
    else cout << -1;
    return 0;
}
