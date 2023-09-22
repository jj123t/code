/*************************************************************************
	> File Name: 2303.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 14:27:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
signed main()
{
    // s
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            int x = phi(i);
            ans += x * (n / i);
            if (i != n / i) {
                int y = phi(n / i);
                ans += y * (n / (n / i));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

