/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 18 Apr 2023 06:33:30 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int p = 1e9 + 7;
signed main () {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    vector<vector<char>> s(n + 1, vector<char>(m + 1));
    vector<int> row(n + 1, 0), col(m + 1, 0), diag(n + m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            s[i][j] = c;
        }
    }
    g[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                row[i] = 0;
                col[j] = 0;
                diag[i + m - j] = 0;
                continue;
            }
            g[i][j] = (g[i][j] + row[i] + col[j] + diag[i + m - j] ) % p;
            row[i] = (row[i] + g[i][j]) % p;
            col[j] = (col[j] + g[i][j]) % p;
            diag[i + m - j] = (g[i][j] + diag[i + m - j]) % p;
        }
    }
    cout << g[n][m] % p;
    return 0;
}
