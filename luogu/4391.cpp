/*************************************************************************
	> File Name: 4391.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 14:51:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int j = 0;
    vector<int> nxt(n + 1);
    for (int i = 2; i <= n; i++) {
        while (j and s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    } 
    cout << n - nxt[n] << "\n";
    return 0;
}

