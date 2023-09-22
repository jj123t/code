/*************************************************************************
	> File Name: 1845c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 22:09:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() 
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        int m; cin >> m;
        string l, r; cin >> l >> r;
        size_t idx = 0;
        for (int i = 0; i < m; i++) {
            size_t to = 0;
            for (char j = l[i]; j <= r[i]; j++) {
                size_t it = s.find_first_of(j, idx);
                to = max(to, it);
            }
            idx = to;
            if (idx != string::npos) idx++;
        }
        if (idx == string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
