/*************************************************************************
	> File Name: 1780d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 19:48:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        int last = 0;
        int t = 0;
        for (int i = 0; i < 30; i++) {
            cout << "- " << (1 << i) - last << endl;
            last = (1 << i);
            int r; cin >> r;
            if (r == n - 1) ans += (1 << i), t++;
            if (t == n) {
                cout << "! " << ans << endl;
                break;
            }
        }
    }
    return 0;
}

