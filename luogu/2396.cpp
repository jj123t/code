/*************************************************************************
	> File Name: 2396.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 19:48:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 24;
int a[(1 << N)], dp[(1 << N)], ev[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    const int p = 1e9 + 7;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[(1 << i)];
    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> ev[i];
    dp[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        a[i] = a[i ^ (i & -i)] + a[i & -i];
        if (a[i] == ev[0] or a[i] == ev[1]) continue;
        for (int j = i; j; j ^= (j & -j)) {
            dp[i] += dp[i ^ (j & -j)];
            dp[i] %= p;
        }
    }
    cout << dp[(1 << n) - 1];
}

