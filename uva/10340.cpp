/*************************************************************************
	> File Name: 10340.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 22:17:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t; 
    while (cin >> s >> t) {
        int n = s.size(), m = t.size();
        int i, j;
        for (i = 0, j = 0; i < n; i++) {
            while (j < m and s[i] != t[j]) j++;
            if (j == m) break;
            j++;
        }
        if (i == n) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

