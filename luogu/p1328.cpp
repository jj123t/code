/*************************************************************************
	> File Name: p1328.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 01:01:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    vector<vector<int>> a(5, vector<int>(5, 0));
    a[0][0] = 0, a[0][1] = -1, a[0][2] = 1, a[0][3] = 1, a[0][4] = -1;
    a[1][1] = 0, a[1][2] = -1, a[1][3] = 1, a[1][4] = -1;
    a[2][2] = 0, a[2][3] = -1, a[2][4] = 1;
    a[3][3] = 0, a[3][4] = 1;
    a[4][4] = 0;
    int m = 5;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            a[j][i] = -1 * a[i][j];
        }
    }
    int n; cin >> n;
    int u, v; cin >> u >> v;
    vector<int> pa(u), pb(v);
    for (auto &x : pa) cin >> x;
    for (auto &y : pb) cin >> y;
    int la = 0, lb = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        int x = pa[la % u];
        la++;
        int y = pb[lb % v];
        lb++;
        if (a[x][y] == 1) ans1++;
        else if (a[x][y] == -1) ans2++;
    }
    cout << ans1 << " " << ans2;
    return 0;
}

