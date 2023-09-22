/*************************************************************************
  > File Name: 10579.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Tue Sep 19 21:55:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int par[100100];
void init(int n) { for (int i = 1; i <= n; i++) par[i] = i; }
int Find(int x) { if (x == par[x]) return x; return par[x] = Find(par[x]); }
void Unite(int x, int y) { par[Find(x)] = Find(y); }
bool Same(int x, int y) { return Find(x) == Find(y); }
int main()
{
    int n, m;
    while (cin >> n >> m) {
        if (m == 0) {
            cout << "Not Possible\n";
            continue;
        }
        vector<int> drgee(n);
        init(n);
        vector<int> vis(n);
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            drgee[u]++, drgee[v]++;
            vis[u] = vis[v] = true;
            Unite(u, v);
        }
        bool flag = true;
        for (int i = 0, last = -1; i < n; i++) {
            if (last == -1 and vis[i]) last = Find(i);
            else if (vis[i] and Find(i) != last) flag = false;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] and drgee[i] % 2 != 0) {
                flag = false;
            }
        }
        if (flag) {
            cout << "Possible\n";
        }
        else {
            cout << "Not Possible\n";
        }
    }
    return 0;
}

