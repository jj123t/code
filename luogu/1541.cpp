/*************************************************************************
	> File Name: 1541.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 22:10:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[41][41][41][41];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> h(4);
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        h[x - 1] += 1;
    }
    int ans = arr[1];
    dp[0][0][0][0] = arr[1];
    for (int a = 0; a <= h[0]; a++) {
        for (int b = 0; b <= h[1]; b++) {
            for (int c = 0; c <= h[2]; c++) {
                for (int d = 0; d <= h[3]; d++) {
                    if (a == 0 and b == 0 and c == 0 and d == 0) continue;
                    int i = 1 + a * 1 + b * 2 + c * 3 + d * 4;
                    int &f = dp[a][b][c][d];
                    int mx = 0;
                    if (a != 0) mx = max(mx, dp[a - 1][b][c][d] + arr[i]);
                    if (b != 0) mx = max(mx, dp[a][b - 1][c][d] + arr[i]);
                    if (c != 0) mx = max(mx, dp[a][b][c - 1][d] + arr[i]);
                    if (d != 0) mx = max(mx, dp[a][b][c][d - 1] + arr[i]);
                    f = max(f, mx);
                    ans = max(ans, f);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

