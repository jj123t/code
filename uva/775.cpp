/*************************************************************************
	> File Name: 775.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 15:19:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n;
int e[500][500];
int vis[500];
bool dfs(int u, int step) {
    if (step >= n) {
        if (e[u][1]) {
            cout << 1 << " ";
            return true;
        }
        return false;
    }
    for (int i = 2; i <= n; i++) {
        if (e[u][i] and !vis[i]) {
            vis[i] = true;
            if (dfs(i, step + 1)) {
                cout << i << " ";
                return true;
            }
            vis[i] = false;
        }
    }
    return false;
}
int main()
{
    while (cin >> n) {
        memset(e, 0, sizeof e);
        memset(vis, 0, sizeof vis);
        string s; cin >> s;
        while (s != "%") {
            int u = 0, v; cin >> v;
            reverse(s.begin(), s.end());
            while (!s.empty()) { u = u * 10 + (s.back() - '0'); s.pop_back(); }
            //cout << u << " " << v << "\n";
            e[u][v] = e[v][u] = 1;
            cin >> s;
        }
        dfs(1, 1);
        cout << 1 << "\n";
    }
    return 0;
}

