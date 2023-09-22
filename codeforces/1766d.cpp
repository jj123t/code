/*************************************************************************
	> File Name: 1766d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 03:37:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> prime;
    vector<int> used(6000, false);
    for (int i = 2; i <= 4000; i++) {
        if (!used[i]) prime.push_back(i);
        for (int j = 2 * i; j <= 4000; j += i) {
            used[j] = true;
        }
    }
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (gcd(a, b) != 1 or (a % 2 == 0 and b % 2 == 0)) {
            cout << 0 << "\n";
        }
        else if (b - a == 1) {
            cout << -1 << "\n";
        }
        else if (a % 2 == 1 and b % 2 == 1) {
            cout << 1 << "\n";
        }
        else {
            int d = b - a;
            // gcd(a + d, b + d) == g;
            // (a - b) % g == 0
            // gcd(a + d, b - a) == g
            // if (b - a) / g = k;
            // (a + d) % k == 0
            // d = k - a % k;
            int ans = 1e9;
            for (auto x : prime) {
                if (d % x == 0) {
                    ans = min(ans, x - a % x);
                    while (d % x == 0) d /= x;
                }
                if (d == 1) break;
            }
            if (d != 1) ans = min(ans, d - a % d);
            cout << ans << '\n';
        }
    }
    return 0;
}


