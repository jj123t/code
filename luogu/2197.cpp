/*************************************************************************
	> File Name: 2197.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 14:19:24 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            ans ^= x;
        }
        if (ans == 0) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}

