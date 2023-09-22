/*************************************************************************
	> File Name: 1808a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 17:32:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        int ans = a;
        int res = 0;
        for (int i = a; i <= min(a + 100, b); i++) {
            string t = to_string(i);
            int mi = 9, mx = 0;
            for (auto c : t) {
                mi = min(mi, c - '0');
                mx = max(mx, c - '0');
            }
            if (mx - mi > res) {
                res = mx - mi;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

