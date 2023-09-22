/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 03:29:56 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1510;
int a[N][N], b[N][N], c[N][N], d[N][N];
int main () {
    int h, w, n, m; cin >> h >> w >> n >> m;
    vector<vector<int>> g(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x][y] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x][y] = 2;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            a[i][j] = b[i][j] = c[i][j] = d[i][j] = 2;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (g[i][j] == 1) {
                a[i][j] = 1;
            }
            else if (g[i][j] == 0) {
                a[i][j] = a[i][j - 1];
            }
            else {
                a[i][j] = 2;
            }
        }
        for (int j = w; j >= 1; j--) {
            if (g[i][j] == 1) {
                b[i][j] = 1;
            }
            else if (g[i][j] == 0) {
                b[i][j] = b[i][j + 1];
            }
            else {
                b[i][j] = 2;
            }
        }
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) {
            if (g[i][j] == 1) {
                c[i][j] = 1;
            }
            else if (g[i][j] == 0) {
                c[i][j] = c[i - 1][j];
            }
            else {
                c[i][j] = 2;
            }
        }
        for (int i = h; i >= 1; i--) {
            if (g[i][j] == 1) {
                d[i][j] = 1;
            }
            else if (g[i][j] == 0) {
                d[i][j] = d[i + 1][j];
            }
            else {
                d[i][j] = 2;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == 1 || b[i][j] == 1 || c[i][j] == 1 || d[i][j] == 1) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}
