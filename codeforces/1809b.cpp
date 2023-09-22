/*************************************************************************
	> File Name: 1809b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 20:30:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int x = sqrt(n);
        if (x * x < n) x++;
        cout << x - 1 << "\n";
    }
    return 0;
}

