/*************************************************************************
	> File Name: 302.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 20 10:08:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct edge {
    int to, label;
    edge(int a = 0, int b = 0) : to(a), label(b) {}
    bool operator < (const edge &x) const {
        return label < x.label;
    }
};
const int N = 2048;
vector<edge> g[N];
int vis[N];
deque<int> path;
void dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        if (!vis[g[u][i].label]) {
            vis[g[u][i].label] = true;
            dfs(g[u][i].to);
            path.push_front(g[u][i].label);
        }
    }
}
int main()
{
    int x, y, z;
    while (true) {
        for (int i = 0; i < N; i++) g[i].clear();
        int e = 0, start = 0;
        while (cin >> x >> y) {
            if (x == 0 and y == 0) break;
            if (e == 0) start = min(x, y);
            cin >> z;
            g[x].push_back(edge(y, z));
            g[y].push_back(edge(x, z));
            e++;
        }
        if (e == 0) break;
        int odd = 1;
        for (int i = 0; i < N; i++) odd &= (g[i].size() % 2 == 0);
        if(!odd) {
    		puts("Round trip does not exist.\n");
    		continue;
    	}
        for (int i = 0; i < N; i++) {
            sort(g[i].begin(), g[i].end());
        }
        memset(vis, 0, sizeof vis);
        path.clear();
        dfs(start);
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " \n"[i == path.size() - 1];
        }
        cout << "\n";
    }
    return 0;
}

