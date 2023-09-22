/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 20:02:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    auto check = [&](int x, int y) {
        if (x + 9 - 1 >= n or y + 9 - 1 >= m) return false;
        for (int i = x; i <= x + 3; i++) {
            for (int j = y; j <= y + 3; j++) {
                if (i == x + 3 or j == y + 3) {
                    if (s[i][j] != '.') return false;
                }
                else 
                    if (s[i][j] != '#') return false;
            }
        }
        for (int i = x + 9 - 1; i >= x + 9 - 3 - 1; i--) {
            for (int j = y + 9 - 1; j >= y + 9 - 3 - 1; j--) {
                if (i == x + 9 - 3 - 1 or j == y + 9 - 3 - 1) {
                    if (s[i][j] != '.') return false;
                }
                else 
                    if (s[i][j] != '#') return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i, j)) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
    return 0;
}

