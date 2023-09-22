/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 28 01:44:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int i1 = i + 1; i1 < n; i1++) { 
            for (int j = 0; j < m; j++) {
                for (int j1 = j + 1; j1 < m; j1++) {
                    int x = a[i][j] + a[i1][j1];
                    int y = a[i1][j] + a[i][j1];
                    if (x > y) {
                        cout << "No";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}

