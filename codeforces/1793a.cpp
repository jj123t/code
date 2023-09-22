/*************************************************************************
	> File Name: 1793a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 13:53:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        int n, m; cin >> n >> m;
        int ans = n * min(a, b);
        int x = n / (m + 1);
        int t = x * m * a;
        int y = n - (x * m) - x;
        cout << min(ans, t + y * min(a, b)) << "\n";
    }
    return 0;
}

