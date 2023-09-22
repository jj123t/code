/*************************************************************************
	> File Name: 5520.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 18:25:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int type, n, m, p; cin >> type >> n >> m >> p;
    int ans = 1;
    for (int i = n - m + 1; i >= n - 2 * m + 2; i--) {
        ans = i * ans % p;
    }
    cout << ans << "\n";
    return 0;
}

