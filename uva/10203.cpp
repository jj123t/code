/*************************************************************************
	> File Name: 10203.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 20 21:27:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int one = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            ans ^= x;
            if (x == 1) one++;
        }
        if (one == n) {
            if (n & 1) cout << "Brother\n";
            else cout << "John\n";
        } 
        else {
            if (ans) cout << "John\n";
            else cout << "Brother\n";
        }
    }
    return 0;
}

