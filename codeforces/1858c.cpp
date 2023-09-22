/*************************************************************************
	> File Name: 1858c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 22:29:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a;
        vector<int> vis(n + 1);
        vector<int> b;
        for (int i = n; i >= 1; i--) {
            if (i & 1) {
                continue;
            }
            if (!vis[i] and !vis[i / 2]) {
                a.push_back(i);
                a.push_back(i / 2);
                vis[i] = vis[i / 2] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) a.push_back(i);
        }
        for (auto x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

