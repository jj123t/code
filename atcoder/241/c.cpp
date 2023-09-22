/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 01:17:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    cout << number % 20220430 << "\n";
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 5 < n) {
                int res = 0;
                for (int k = 0; k < 6; k++) res += s[i + k][j] == '.'; 
                ans |= (res <= 2);
            }
            if (j + 5 < n) {
                int res = 0;
                for (int k = 0; k < 6; k++) res += s[i][k + j] == '.';
                ans |= (res <= 2);
            }
            if (i + 5 < n && j + 5 < n) {
                int res = 0;
                for (int k = 0; k < 6; k++) res += s[i + k][j + k] == '.';
                ans |= (res <= 2);
            }
            if (i - 5 >= 0 && j + 5 < n) {
                int res = 0;
                for (int k = 0; k < 6; k++) {
                    res += s[i - k][j + k] == '.';
                }
                ans |= (res <= 2);
            }
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}

