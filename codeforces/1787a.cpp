/*************************************************************************
	> File Name: 1787a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 23:01:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << 1 << " " << n / 2 << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}

