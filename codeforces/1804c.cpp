/*************************************************************************
	> File Name: 1804c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 23:23:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, x, p; cin >> n >> x >> p;
        // (x + f * (f + 1) / 2) % n
        // x + f * (f + 1) / 2 = n * k
        // f * (f + 1) = 2 * (n * k - x);
        bool flag = false;
        for (int i = 1; i <= min(p, 2 * n); i++) {
            int d = x + i * (i + 1) / 2;
            if (d % n != 0) continue;
            flag = true;
            break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

