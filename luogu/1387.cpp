/*************************************************************************
	> File Name: 1387.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 18:36:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int res = 1; res <= n; res++) {
        int t = res * res;
        for (int i = res; i <= n; i++) {
            for (int j = res; j <= m; j++) {
                int r = a[i][j] - a[i - res][j] - a[i][j - res] + a[i - res][j - res];
                if (r == t) {
                    ans = max(ans, res);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

