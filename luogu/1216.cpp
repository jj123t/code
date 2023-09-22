/*************************************************************************
	> File Name: 1216.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 19:20:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r; cin >> r;
    vector<vector<int>> arr(r + 1, vector<int>(r + 1, 0));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        ans = max(ans, arr[r][i]);
    }
    cout << ans << "\n";
    return 0;
}

