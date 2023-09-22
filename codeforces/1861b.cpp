/*************************************************************************
	> File Name: 1861b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 31 22:07:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string a, b; cin >> a >> b;
        int n = a.size();
        set<int> one, zero;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0' and b[i] == '0') {
                zero.insert(i);
            }
            if (a[i] == '1' and b[i] == '1') {
                one.insert(i);
            }
        }
        if (one.count(0)) {
            if (one.count(n - 1)) flag = true;
            for (auto x : one) {
                if (zero.count(x + 1) and zero.count(n - 1)) {
                    flag = true;
                }
            }
        }
        else if (zero.count(0)) {
            if (zero.count(n - 1)) flag = true;
            for (auto x : zero) {
                if (one.count(x + 1) and one.count(n - 1)) {
                    flag = true;
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
     }
    return 0;
}

