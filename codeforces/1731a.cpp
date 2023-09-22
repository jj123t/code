/*************************************************************************
	> File Name: 1731a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 10:36:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        long long tmp = 1;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            tmp *= x;
        }
        cout << (2022ll) * (tmp + n - 1) << "\n";
    }
    return 0;
}

