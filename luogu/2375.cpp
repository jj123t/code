/*************************************************************************
	> File Name: 2375.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 10 12:45:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    const int p = 1e9 + 7;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        int j = 0;
        vector<int> nxt(n + 1);
        vector<int> res(n + 1);
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            while (j and s[i] != s[j + 1]) j = nxt[j]; 
            if (s[i] == s[j + 1]) j++;
            nxt[i] = j;
            res[i] = res[j] + 1;
        }
        int ans = 1;
        j = 0;
        for (int i = 2; i <= n; i++) {
            while (j and s[i] != s[j + 1]) j = nxt[j];
            if (s[i] == s[j + 1]) j++;
            while (j * 2 > i) j = nxt[j];
            ans = ans * (res[j] + 1) % p;
        }
        cout << ans << "\n";
    }
    return 0;
}

