/*************************************************************************
	> File Name: 5596.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 12:14:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int a, b; cin >> a >> b;
    if (a * a - 4 * b == 0) {
        cout << "inf\n";
        return 0;
    }
    int flag = 1;
    int ans = 0;
    int t = a * a - 4 * b;
    if (t < 0) {
        flag = -1;
        t *= -1;
    }
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            int d = t / i;
            if (d + i * flag - a * 2 >= 0 and (d + i * flag - a * 2) % 4 == 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

