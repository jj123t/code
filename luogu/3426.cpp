/*************************************************************************
	> File Name: 3426.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 30 18:07:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> nxt(n + 1);
    int j = 0;
    for (int i = 2; i <= n; i++) {
        while (j and s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
    vector<int> dp(n + 1), h(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        if (h[dp[nxt[i]]] >= i - nxt[i]) dp[i] = dp[nxt[i]];
        h[dp[i]] = i;
    }
    cout << dp[n];
    return 0;
}

