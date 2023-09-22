/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 19:53:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(4, vector<int>(4, 0));
    int cnt = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = cnt++;
        }
    }
    bool flag = false;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == n) {
                if (j - 1 >= 0) 
                    if (arr[i][j - 1] == m) {
                        flag = true;
                    }
                if (j + 1 < 3) 
                    if (arr[i][j + 1] == m) {
                        flag = true;
                    }
            }
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

