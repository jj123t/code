/*************************************************************************
	> File Name: 1796c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 22:43:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        int t = log2(r / l) ;
        int ans = 0;
        const int p = 998244353;
        ans += (r / (1 << t)) - l + 1;
        ans %= p;
        ans += max(0, r / (1 << (t - 1)) / 3 - l + 1) * t % p;
        ans %= p;
        cout << t + 1 << " " << ans % p <<"\n";
    }
    return 0;
}

