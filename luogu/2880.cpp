/*************************************************************************
	> File Name: 2880.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 13:56:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> st(n + 1, vector<int>(28, 0));
    vector<vector<int>> st2(n + 1, vector<int>(28, 0));
    for (int i = 1; i <= n; i++) cin >> st[i][0];
    for (int i = 1; i <= n; i++) st2[i][0] = st[i][0];
    for (int j = 1; j <= 25; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto get = [&](int l, int r) {
        int x = log2(r - l + 1);
        return max(st[l][x], st[r - (1 << x) + 1][x]) - min(st2[l][x], st2[r - (1 << x) + 1][x]);
    };
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}

