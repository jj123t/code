/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May  9 03:54:45 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        bool flag = true;
        bool all = false;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                flag = false;
            }
        } 
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) all = true;
        }
        if (!flag) cout << n << "\n";
        else {
            if (all) cout << n - 1 << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}
