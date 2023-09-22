/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 16 Apr 2023 05:20:39 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3010;
int maze[N][N];
int f[N][N][4];
int main () {
    int n, m, k; cin >> n >> m >> k;
    n++, m++;
    for (int i = 0; i < k; i++) {
        int r, c, v; cin >> r >> c >> v;
        r--, c--;
        maze[r][c] = v;
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int op = 0; op <= 3; op++) {
                if (x + 1 < n) {
                    f[x + 1][y][0] =  max(f[x + 1][y][0], f[x][y][op] + (op + 1 <= 3 ? maze[x][y] : 0));
                }
                if (y + 1 < m) {
                    f[x][y + 1][op] = max(f[x][y + 1][op], f[x][y][op]);
                    if (op + 1 <= 3) {
                        f[x][y + 1][op + 1] = max(f[x][y + 1][op + 1], f[x][y][op] + maze[x][y]);
                    }
                }
            }
        }
    }
    cout << f[n-1][m-1][0];
    return 0;
}
