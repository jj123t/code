/*************************************************************************
	> File Name: 1783b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 16:25:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        int cnt = 1;
        int cur = n * n;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = n - 1 - (n & 1); j > -1; j -= 2) {
                    a[i][j] = cnt++;
                }
            }
            else {
                for (int j = 0; j < n; j += 2) {
                    a[i][j] = cnt++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = n - (n % 2 == 1 ? 1 : 2); j > -1; j -= 2) {
                    a[i][j] = cur--;
                }
            }
            else {
                for (int j = 1; j < n; j += 2) {
                    a[i][j] = cur--;
                }
            }
        }
        for (int i  =0 ; i <n ;i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

