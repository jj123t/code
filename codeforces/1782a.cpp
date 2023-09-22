/*************************************************************************
	> File Name: 1782a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 11:44:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int w, d, h; cin >> w >>d >> h;
        int a, b, f, g; cin >> a >>b >> f >> g;
        int ans = 1e9;
        ans = min(ans, abs(a - f) + g + b + h);
        ans = min(ans, abs(a - f) + h + d - b + d - g);
        ans = min(ans, abs(b - g) + h + a + f);
        ans = min(ans, abs(b - g) + h + w - a + w - f);
        cout << ans << "\n";
    }
    return 0;
}

