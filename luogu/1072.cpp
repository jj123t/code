/*************************************************************************
	> File Name: 1072.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 20:46:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a0, a1, b0, b1; cin >> a0 >> a1 >> b0 >> b1;
        int ans = 0;
        for (int i = 1; i * i <= b1; i++) {
            if (b1 % i == 0) {
                if (lcm(i, b0) == b1 and gcd(i, a0) == a1) ans++;
                if (b1 != i * i) {
                    if (lcm(b1 / i, b0) == b1 and gcd(b1 / i, a0) == a1) ans++;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

