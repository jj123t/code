/*************************************************************************
	> File Name: 1816.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 19:37:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n; cin >> m >> n;
    vector<vector<int>> st(m + 1, vector<int>(30, 0));
    for (int i = 1; i <= m; i++) cin >> st[i][0];
    for (int j = 1; j <= 27; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto get = [&](int l, int r) {
        int x = log2(r - l + 1);
        return min(st[l][x], st[r - (1 << x) + 1][x]);
    };
    while (n--) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << " ";
    }
    return 0;
}

