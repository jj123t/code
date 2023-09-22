/*************************************************************************
	> File Name: 1613.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 09:19:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 200;
const int INF = 1e9;
int dis[N][N], e[N][N][N];
signed main()
{
    memset(dis, 0x3f, sizeof dis);
    memset(e, 0, sizeof e);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u][v][0] = true;
        dis[u][v] = 1;
    }
    for (int p = 1; p <= 32; p++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (e[i][k][p - 1] and e[k][j][p - 1]) {
                        e[i][j][p] = true, dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j and j != k and k != i)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << dis[1][n];
    return 0;
}

