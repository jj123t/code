/*************************************************************************
	> File Name: 1199.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 21:03:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + 1 + n);
        if (ans <= a[i][n - 1]) {
            ans = a[i][n - 1];
        }
    }
    cout << 1 << "\n";
    cout << ans << "\n";
    return 0;
}

