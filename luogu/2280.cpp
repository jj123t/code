/*************************************************************************
	> File Name: 2280.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 19:22:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a[5010][5010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y, v; cin >> x >> y >> v;
        x++, y++;
        a[x][y] += v;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = m; i <= 5001; i++) {
        for (int j = m; j <= 5001; j++) {
            ans = max(ans, a[i][j] - a[i - m][j] - a[i][j - m] + a[i - m][j - m]);
        }
    }
    cout << ans << '\n';
    return 0;
}

