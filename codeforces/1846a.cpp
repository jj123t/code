/*************************************************************************
	> File Name: 1846a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul  7 22:28:16 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            if (x > y) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

