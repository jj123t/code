/*************************************************************************
	> File Name: 1229.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 22:12:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    string s, t; 
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j < t.size(); j++) {
            if (s[i] == t[j] and s[i + 1] == t[j - 1]) {
                ans++;
            }
        }
    }
    cout << (1 << ans) << "\n";
    return 0;
}

