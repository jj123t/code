/*************************************************************************
	> File Name: 1560.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 09:44:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    for (int cnt = 1; cnt <= tt; cnt++) {
        int n = 30;
        vector<vector<int>> A(31, vector<int>(31));
        vector<vector<int>> ans(30, vector<int>(30));
        int dx[5] = {0, 1, 0, -1, 0};
        int dy[5] = {0, 0, 1, 0, -1};
        for (int i = 0; i < n; i++) cin >> A[i][n];
        for (int i = 0; i < n; i++) {
            int x = i / 6, y = i % 6;
            for (int j = 0; j < 5; j++) {
                int rx = x + dx[j];
                int ry = y + dy[j];
                if (rx < 0 or rx >= 5 or ry < 0 or ry >= 6) continue;
                A[i][rx * 6 + ry] = 1;
            }
        }
        auto gauss = [&]() {
            for (int i = 0; i < n; i++) {
                int k = i;
                while (k < n) { if (A[k][i]) break; k++; } 
                for (int j = 0; j <= n; j++) swap(A[i][j], A[k][j]);
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (A[j][i]) {
                        for (int k = i; k <= n; k++) {
                            A[j][k] ^= A[i][k];
                        }
                    }
                }
            }
            for (int i = n - 1; i >= 0; i--) ans[i / 6][i % 6] = A[i][n];
        };
        gauss();
        cout << "PUZZLE #" << cnt << "\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << ans[i][j] << " ";
            }
            cout << ans[i][5] << "\n";
        }
    }
    return 0;
}

