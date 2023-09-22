/*************************************************************************
	> File Name: 1766c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 00:37:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<char>> s(n + 1, vector<char>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                cin >> s[i][j];
            }
        }
        vector<bool> flag(2, true);
        for (int i = 0; i < n; i++) {
            if (s[i][0] == 'B' && s[i][1] == 'B') {
                swap(flag[0], flag[1]);
            }
            else if (s[i][0] == 'B') {
                flag[1] = false;
            }
            else {
                flag[0] = false;
            }
        }
        if (flag[0] || flag[1]) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}

