/*************************************************************************
	> File Name: 5657.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 21:16:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    unsigned long long n, k; cin >> n >> k;
    unsigned long long x = pow(2, n - 1);
    bool flag = true;
    while (x) {
        if (flag) {
            if (k < x) cout << "0";
            else {
                cout << "1";
                k -= x;
                flag = false;
            }
        }
        else {
            if (k < x) cout << "1", flag = true;
            else {
                cout << "0";
                k -= x;
            }
        }
        x >>= 1ll;
    }
    return 0;
}

