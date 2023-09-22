/*************************************************************************
	> File Name: 1873c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 22:44:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int f(int x, int y) {
    if ((x == 5 or x == 6) and (y == 5 or y == 6)) {
        return 5;
    }
    else if ((4 <= x and x <= 7) and (4 <= y and y <= 7)) {
        return 4;
    }
    else if ((3 <= x and x <= 8) and (3 <= y and y <= 8)) {
        return 3;
    }
    else if ((2 <= x and x <= 9) and (2 <= y and y <= 9)) {
        return 2;
    }
    else {
        return 1;
    }
}
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n = 10;
        vector<string> s(n + 1);
        int ans = 0;
        for (int i = 1;  i<= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j - 1] == 'X') {
                    ans += f(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

