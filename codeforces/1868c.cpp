/*************************************************************************
	> File Name: 1868c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep 10 21:57:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> arr(n + 1, vector<int>(m + 1));
        if (n < m) {
            cout << n + 1 << '\n';
            for (int i = 1; i <= n; i++) {
                int right = m - i, left = 0;
                for (int j = 1; j <= m; j++) {
                    if (j <= i) arr[i][j] = right++;
                    else arr[i][j] = left++;
                }
            }
        }
        else {
            if (m == 1) {
                cout << 0 << '\n';
            }
            else {
                cout << m << "\n";
            }
            for (int i = 1; i < m; i++) {
                int right = m - i, left = 0;
                for (int j = 1; j <= m; j++) {
                    if (j <= i) {
                        arr[i][j] = right++;
                    }
                    else {
                        arr[i][j] = left++;
                    }
                }
            }
            for (int i = m; i <= n; i++) arr[i] = arr[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

