/*************************************************************************
	> File Name: 3865.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 03:24:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
int st[200000][31];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> st[i][0];
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
    while (m--) {
        int l, r; cin >> l >> r;
        int x = log2(r - l + 1);
        cout << max(st[l][x], st[r - (1 << x) + 1][x]) << "\n";
    }
    return 0;
}

