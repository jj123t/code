/*************************************************************************
	> File Name: 1775b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 10 20:07:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        map<int, int> mp[n];
        set<int> st; map<int, int> has;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                mp[i][x]++;
                st.insert(x); has[x]++;
            }
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (auto x : mp[i]) {
                if (has[x.first] == x.second) flag = true;
            }
            if (!flag) {
                ok = true;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

