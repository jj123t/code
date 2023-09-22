/*************************************************************************
	> File Name: 4054.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 23:21:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int tree[101][301][301];
int arr[301][301];
int n, m;
void add(int c, int x, int y, int z) {
    for (int  i = x; i <= n; i += (i & -i)) {
        for (int j = y; j <= m; j += (j & -j)) {
            tree[c][i][j] += z;
        }
    } 
}
int qry(int c, int x, int y) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) {
        for (int j = y; j; j -= (j & -j)) {
            res += tree[c][i][j];
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x; arr[i][j] = x;
            add(x, i, j, 1);
        }
    }
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, c; cin >> x >> y >> c;
            add(arr[x][y], x, y, -1);
            arr[x][y] = c;
            add(arr[x][y], x, y, 1);
        }
        else {
            int x1, x2, y1, y2, c; cin >> x1 >> x2 >> y1 >> y2 >> c;
            cout << qry(c, x2, y2) + qry(c, x1 - 1, y1 - 1) - qry(c, x1 - 1, y2) - qry(c, x2, y1 - 1) << "\n";
        }
    }
    return 0;
}

