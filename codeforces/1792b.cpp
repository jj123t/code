/*************************************************************************
	> File Name: 1792b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 19:37:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a == 0) {
            cout << 1 << "\n";
        }
        else {
            int ans = 0;
            int e = min(b, c);
            ans += a + 2 * e;
            b -= e, c -= e;
            if (a >= max(b, c) + d) {
                ans += max(b, c) + d;
            }
            else {
                ans += a + 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}

