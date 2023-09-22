/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 11:58:42 AM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    string a, b; cin >> b >> a;
    vector<vector<int>> dp(n + 1, vector<int>(7));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'T') {
            for (int j = 0; j < 7; j++) {
                dp[i + 1][j] = (dp[i][(j * 10) % 7] || dp[i][(j * 10 + (b[i] - '0')) % 7]);
            }
        }
        else {
            for (int j = 0; j < 7; j++) {
                dp[i + 1][j] = (dp[i][(j * 10) % 7] && dp[i][(j * 10 + (b[i] - '0')) % 7]);
            }
        }
    }
    cout << (dp[n][0] ? "Takahashi" : "Aoki");
    return 0;
}
