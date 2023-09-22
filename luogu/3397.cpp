/*************************************************************************
	> File Name: 3397.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 18:55:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> pfx(n + 2, vector<int>(n + 2));
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        pfx[x1][y1]++;
        pfx[x1][y2 + 1]--;
        pfx[x2 + 1][y1]--;
        pfx[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
            cout << pfx[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

