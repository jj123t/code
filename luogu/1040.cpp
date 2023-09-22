/*************************************************************************
	> File Name: 1040.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 16:17:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][N];
int pre[N][N];
void print(int l, int r) {
    if (l > r) return ;
    cout << pre[l][r] << " ";
    if (l == r) return ;
    print(l, pre[l][r] - 1);
    print(pre[l][r] + 1, r);
}
int main()
{
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) dp[i][i] = arr[i], dp[i][i - 1] = 1, pre[i][i] = i;
    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            for (int k = i; k < j; k++) {
                if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k]) {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    pre[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
    print(1, n);
    return 0;
}

