/*************************************************************************
	> File Name: 2261.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 17:03:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, k; cin >> n >> k;
    int ans = n * k;
    for (int l = 1, r = 0; l <= n; l = r + 1) {
        if (k / l == 0) r = n;
        else r = min(n, k / (k / l));
        ans -= (k / l) * (l + r) * (r - l + 1) / 2;
    }
    cout << ans ;
    return 0;
}

