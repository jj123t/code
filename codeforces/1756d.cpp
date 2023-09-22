/*************************************************************************
	> File Name: 1756d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul  3 20:59:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') l += l + 1;
        else r += r + 1;
    }
    for (int i = l + 1; i <= (1 << n) - r; i++) {
        cout << i << " ";
    }
    return 0;
}

