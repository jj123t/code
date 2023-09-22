/*************************************************************************
	> File Name: 1846b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul  7 22:28:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        vector<vector<int>> arr(3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c; cin >> c;
                if (c == '+') arr[i][j] = 1;
                else if (c == 'O') arr[i][j] = 0;
                else if (c == '.') arr[i][j] = 2;
                else arr[i][j] = -1;
            }
        }
        int ans = -2;
        for (int i = 0; i < 3; i++) {
            bool flag = true;
            for (int j = 1; j < 3; j++) {
                if (arr[i][j] != arr[i][j - 1]) flag = false;
            }
            if (flag) ans = arr[i][0];
        }
        for (int i = 0; i < 3; i++) {
            bool flag = true;
            for (int j = 1; j < 3; j++) {
                if (arr[j][i] != arr[j - 1][i]) flag = false;
            }
            if (flag) ans = arr[0][i];
        }
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
            ans = arr[0][0];
        }
        if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
            ans = arr[0][2];
        }
        if (ans == 0) cout << "O" <<"\n";
        else if (ans == 1) cout << "+" << "\n";
        else if (ans == -1) cout << "X" << "\n";
        else cout << "DRAW" << "\n";
    }
    return 0;
}

