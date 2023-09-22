/*************************************************************************
	> File Name: 1861a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 31 22:07:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    vector<int> vis(100100, false);
    for (int i = 2; i <= 100000; i++) {
        for (int j = 2 * i; j <= 100000; j += i) {
            vis[j] = true;
        }
    }
    set<int> st;
    for (int i = 2; i <= 100000; i++) {
        if (!vis[i]) {
            string s = to_string(i);
            if (s.size() < 2) continue; 
            set<int> tmp;
            for (auto c : s) {
                tmp.insert(c);
            }
            if (tmp.size() == s.size()) {
                st.insert(i);
            }
        }
    }
    while (tt--) {
        string s; cin >> s;
        bool flag = false;
        int ans = -1;
        for (auto x : st) {
            string t = to_string(x);
            int j = 0;
            for (auto c : s) {
                if (j < t.size() and c == t[j]) j++;
                if (j == t.size()) {
                    flag = true;
                    ans = x;
                    break;
                }
            }
            if (flag) break;
        }
        cout << ans << "\n";
    }
    return 0;
}

