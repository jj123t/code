/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 12:50:47 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
double dp[N][N][N];
int main () {
    int a, b, c; cin >> a >> b >> c;
    dp[a][b][c] = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if (i + j + k == 0) continue;
                double x = i + j + k;
                dp[i + 1][j][k] += dp[i][j][k] * i / x;
                dp[i][j + 1][k] += dp[i][j][k] * j / x;
                dp[i][j][k + 1] += dp[i][j][k] * k / x;
            }
        }
    }
    double ans = 0;
    for (int i = 0; i <= 100; i++ ) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) { 
                if (i == 100 || j == 100 || k == 100) {
                    ans += dp[i][j][k] * (i + j + k - a - b - c);
                }
            }
        }
    }
    cout << fixed << setprecision(20) << ans << "\n";
    return 0;
}
