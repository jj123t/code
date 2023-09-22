/*************************************************************************
	> File Name: 3435.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 16:42:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> nxt(n + 1);
    string s; cin >> s;
    s = " " + s;
    int j = 0;
    for (int i = 2; i <= n; i++) {
        while (j and s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (nxt[j] != 0) j = nxt[j];
        if (nxt[i] != 0) nxt[i] = j;
        ans += i - j;
    }
    cout << ans << "\n";
    return 0;
}

