/*************************************************************************
	> File Name: 1853b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 22:25:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int now = n - i;
            int last = n;
            int cnt = 0;
            while (true) { 
                int tmp = now;
                now = last - now;
                last = tmp;
                cnt++;
                if (cnt == k) {
                    ans++;
                    break;
                }
                if (now < 0) break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

