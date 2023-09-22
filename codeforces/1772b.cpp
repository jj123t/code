/*************************************************************************
	> File Name: 1772b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 10:48:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        vector<vector<int>> arr(2, vector<int>(2, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> arr[i][j];
            }
        }
        int m = 8;
        bool flag = false;
        while (m--) {
            int t = arr[0][0]; arr[0][0] = arr[1][0]; arr[1][0] = arr[1][1];
            arr[1][1] = arr[0][1]; arr[0][1] = t;
            if (arr[0][1] > arr[0][0] and arr[1][1] > arr[1][0] and arr[1][0] > arr[0][0] and arr[1][1] > arr[0][1]) { flag = true; break; }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

