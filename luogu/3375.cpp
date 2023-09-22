/*************************************************************************
	> File Name: 3375.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 18:47:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t; cin >> s >> t;
    int a = s.size(), b = t.size();
    s = " " + s, t = " " + t;
    vector<int> nxt(b + 1);
    int j = 0;
    for (int i = 2; i <= b; i++) {
        while (j and t[i] != t[j + 1]) j = nxt[j];
        if (t[i] == t[j + 1]) j++;
        nxt[i] = j;
    }
    j = 0;
    for (int i = 1; i <= a; i++) {
        while (j > 0 and s[i] != t[j + 1]) j = nxt[j];
        if (s[i] == t[j + 1]) j++;
        if (j == b) {
            cout << i - b + 1 << "\n";
            j = nxt[j];
        }
    }
    for (int i = 1; i <= b; i++) {
        cout << nxt[i] << " ";
    }
    return 0;
}

