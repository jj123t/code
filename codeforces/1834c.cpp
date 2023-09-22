/*************************************************************************
	> File Name: 1834c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 10 16:57:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        int ans = 1e9;
        int res1 = 0;
        for (int i = 0; i < n; i++) {
            res1 += (s[i] != t[i]);
        }
        if (res1 == 0) ans = min(ans, 0);
        else if (res1 & 1) ans = min(ans, 2 * res1 - 1);
        else ans = min(ans, res1 * 2);
        reverse(t.begin(), t.end());
        int res2 = 0;
        for (int i = 0; i < n; i++) {
            res2 += (s[i] != t[i]);
        }
        if (res2 == 0) ans = min(ans, 2);
        else if (res2 & 1) ans = min(ans, res2 * 2);
        else ans = min(ans, res2 * 2 - 1);
        cout << ans << "\n";
    }
    return 0;
}

