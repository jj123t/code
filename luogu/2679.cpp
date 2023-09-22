/*************************************************************************
	> File Name: 2679.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 12:21:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[2][201][201][2];
const int p = 1e9 + 7;
int main()
{
    int n, m, l; cin >> n >> m >> l;
    string s, t; cin >> s >> t;
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= l; k++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i % 2][j][k][1] = ((dp[(i + 1) % 2][j - 1][k - 1][1] + dp[(i + 1) % 2][j - 1][k - 1][0]) % p + dp[(i + 1) % 2][j - 1][k][1]) % p;
                    dp[i % 2][j][k][0] = (dp[(i + 1) % 2][j][k][0] + dp[(i + 1) % 2][j][k][1] ) % p;
                }
                else {
                    dp[i % 2][j][k][0] = dp[(i + 1) % 2][j][k][0] + dp[(i + 1) % 2][j][k][1] % p;
                    dp[i % 2][j][k][1] = 0;
                }
            }
        } 
    }
    cout << (dp[n % 2][m][l][0] + dp[n % 2][m][l][1]) % p << '\n';
    return 0;
}

