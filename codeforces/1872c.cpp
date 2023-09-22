/*************************************************************************
	> File Name: 1872c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep  7 22:18:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        if (l == r) {
            if (l % 2 == 0 and l - 2 != 0) {
                cout << 2 << " " << l - 2 << "\n";
            }
            else {
                int idx = -1;
                for (int i = 2; i * i <= l; i++) {
                    if (l % i == 0) {
                        idx = i;
                        break;
                    }
                }
                if (idx == -1 and idx != 1) {
                    cout << -1 << "\n";
                }
                else {
                    cout << (idx - 1) * (l / idx) << " " << l / idx << "\n";
                }
            }
        }
        else {
            int t = r;
            if (r & 1) t--;
            if (t - 2 == 0) {
                cout << -1 << "\n";
                continue;
            }
            if (t % 2 == 0) {
                cout << 2 << " " << t - 2 << '\n';
            }
            else {
                cout << 2 << " " << t + 1 - 2 << "\n";
            }
        }
    }
    return 0;
}

