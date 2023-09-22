/*************************************************************************
	> File Name: 1761a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 21:49:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        int d = n - a - b;
        if (a == n && b == n) {
            cout << "YES\n";
            continue;
        }
        if (d == 0) {
            cout << "NO\n";
        }
        else if (d > 1) {
            cout << "YES\n";
        }
        else if (d == 1) {
            cout << "NO\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}

