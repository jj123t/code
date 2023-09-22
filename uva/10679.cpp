/*************************************************************************
  > File Name: 10679.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Thu Sep  7 20:15:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> fail(1e6);
void getfail(string p) {
    fail[0] = -1;
    int i = 0, j = -1;
    while (i < p.size() - 1) {
        if (j == -1 or p[i] == p[j]) {
            i++, j++;
            if (p[i] != p[j]) fail[i] = j;
            else fail[i] = fail[j];
        }
        else j = fail[j];
    }
}
bool kmp(string s, string p) {
    int i = 0, j = 0;
    while (i < s.size() and j < (int)p.size()) {
        if (j == -1 or s[i] == p[j]) j++, i++;
        else j = fail[j];
    }
    return j == (int)p.size();
}
int main()
{
    int tt;  cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int q; cin >> q;
        while (q--) {
            string p; cin >> p; getfail(p);
            if (kmp(s, p)) cout << "y\n";
            else cout << "n\n";
        }
    }
    return 0;
}

