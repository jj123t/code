/*************************************************************************
	> File Name: 1842a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:59:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        int sa = 0, sb = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            sa += x;
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            sb += x;
        }
        if (sa == sb) cout << "Draw\n";
        else if (sa > sb) cout << "Tsondu\n";
        else cout << "Tenzing\n";
    }
    return 0;
}

