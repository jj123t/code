/*************************************************************************
	> File Name: cf687b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 18:21:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    int x = 1;
    for (int i = 1; i <= n; i++) {
        int r; cin >> r;
        x = lcm(x, r);
        x %= k;
    }
    if (x % k == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}

