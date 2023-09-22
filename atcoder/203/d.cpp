/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 09:03:22 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int n, k; cin >> n >> k;
    vector<vector<int>> e(n + 1, vector<int>(n + 1));
    auto a = e;
    int left = 1e9, right = -1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e[i][j];
            left = min(left, e[i][j]);
            right = max(right, e[i][j]);
        }
    }
    auto check = [&](int x) -> bool {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (e[i][j] <= x);
            }
        }
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int d = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
                if (d >= (k * k + 1) / 2) return true;
            }
        }
        return false;
    };
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << left;
    return 0;
}
