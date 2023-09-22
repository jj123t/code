/*************************************************************************
	> File Name: 1872a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep  7 22:18:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c; cin >> a >> b >> c;
        double d = (a + b) / 2.0;
        cout << ceil(((double)max(a, b) - d) / c) << '\n';
    }
    return 0;
}

