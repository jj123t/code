/*************************************************************************
	> File Name: 3287.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  8 14:58:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[10010][510], tree[550][5500];
int ans = 0;
int n, k;
void add(int x, int y, int t) {
    for (int i = x; i <= k + 1; i += (i & -i)) {
        for (int j = y; j <= 5500; j += (j & -j)) {
            tree[i][j] = max(tree[i][j], t);
        }
    }
}
int qry(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) {
        for (int j = y; j; j -= (j & -j)) {
            res = max(res, tree[i][j]);
        }
    }
    return res;
}
int main()
{
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 0; j--) {
            dp[i][j] = qry(j + 1, arr[i] + j) + 1;
            add(j + 1, arr[i] + j, dp[i][j]);
        }
    }
    cout << qry(k + 1, 5500) << "\n";
    return 0;
}

