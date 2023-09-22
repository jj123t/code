/*************************************************************************
	> File Name: 6577.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 21:52:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 550;
int n, m;
const int INF = 1e18;
int e[N][N], match[N], slack[N], ex[N], ey[N], pre[N];
bool visx[N], visy[N];
int d;

void dfs(int u) {

    int x, y = 0, yy = 0, delta = 0;
    fill(pre, pre + n + 1, 0);
    for (int i = 1; i <= n; i++) slack[i] = INF;
    match[y] = u;

    while (true) {
        x = match[y]; delta = INF; visy[y] = 1;

        for (int i = 1; i <= n; i++) {
            if (visy[i]) continue;
            if (slack[i] > ex[x] + ey[i] - e[x][i]) {
                slack[i] = ex[x] + ey[i] - e[x][i];
                pre[i] = y;
            }
            if (slack[i] < delta) {
                delta = slack[i];
                yy = i;
            }
        }

        for (int i = 0; i <= n; i++) {
            if (visy[i]) {
                ex[match[i]] -= delta;
                ey[i] += delta;
            }
            else {
                slack[i] -= delta;
            }
        }

        y = yy;
        if (match[y] == -1) break;
    }

    while (y) {
        match[y] = match[pre[y]];
        y = pre[y];
    }

}
int KM() {
    fill(match, match + n + 1, -1);
    fill(ex, ex + n + 1, 0);
    fill(ey, ey + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        fill(visy, visy + n + 1, 0);
        dfs(i);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (match[i] != -1) {
            res += e[match[i]][i];
        }
    }
    return res;

}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = -INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u][v] = w;
    }
    cout << KM() << "\n";
    for (int i = 1; i <= n; i++) {
        cout << match[i] << " ";
    }
    return 0;
}

