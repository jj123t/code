/*************************************************************************
	> File Name: 5436.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 22:12:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) cout << 1 << "\n";
        else  cout << lcm(n, n - 1) << "\n";
    }
    return 0;
}

