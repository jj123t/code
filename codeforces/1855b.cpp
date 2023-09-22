/*************************************************************************
	> File Name: 1855b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 21:49:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int i = 1;
        while (n % (i + 1) == 0) {
            i++;
        }
        cout << i << "\n";
    }
    return 0;
}

