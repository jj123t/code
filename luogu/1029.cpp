/*************************************************************************
	> File Name: 1029.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 22:31:24 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    /*
    gcd(a, b) = x0
    lcm(a, b) = y0
    lcm(a, b) = a * b / gcd(a, b) = y0
    a * b = x0 * y0;
    */
    int a, b; cin >> a >> b;
    int d = a * b;
    int ans = 0;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            int x = i, y = d / i;
            if (gcd(x, y) == a and lcm(x, y) == b) {
                if (x != y) ans += 2;
                else ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

