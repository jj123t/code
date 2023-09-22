/*************************************************************************
	> File Name: 2251.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 19:30:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<vector<int>> st(n + 1, vector<int>(30, 0));
    for (int i = 1; i <= n; i++) st[i][0] = arr[i];
    for (int j = 1; j <= 28; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto get = [&](int l, int r) {
        int x = log2(r - l + 1);
        return min(st[l][x], st[r - (1 << x) + 1][x]);
    };
    for (int i = 0; i < n - m + 1; i++) {
        cout << get(i + 1, m + i) << "\n";
    }
    return 0;
}

