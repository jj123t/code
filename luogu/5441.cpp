/*************************************************************************
	> File Name: 5441.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 21:03:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= i + (n + 1) / 2; j++) {
            a[i][(j - 1 + n) % n + 1] = 1;
        }
    }
    if (n == 1) {
        cout << 0 << "\n" << 0 << "\n";
        return 0;
    } 
    else {
        int t = (n - 3) / 2;
        cout << n * (n - 1) * (n - 2) * (n - 3) / 1 / 2 / 3 / 4 - n * (t) * (t - 1) * (t - 2) / 6;
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

