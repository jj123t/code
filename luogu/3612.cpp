/*************************************************************************
	> File Name: 3612.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 18 21:50:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    string s; cin >> s;
    int n; cin >> n;
    int m = s.size();
    while (m < n) {
        int i = m;
        while (n > i) i *= 2;
        i = i / 2;
        n -= (i + 1);
        if (n == 0) n = i;
    }
    cout << s[n - 1];
    return 0;
}

