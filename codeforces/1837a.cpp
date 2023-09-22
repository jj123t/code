/*************************************************************************
	> File Name: 1837a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 21:46:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        if (n % k == 0) {
            cout << 2 << " " << 1 << " " << n - 1 << "\n";
        }
        else {
            cout << 1 << " " << n << "\n";
        }
    }
    return 0;
}

