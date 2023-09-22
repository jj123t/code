/*************************************************************************
	> File Name: 2822.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 17:28:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5000;
int c[N][N], s[N][N];
int k;
void init() {
    c[1][1] = 1;
    for (int i = 0; i <= 2000; i++) c[i][0] = 1;
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (c[i][j] == 0) s[i][j]++;
        }
        s[i][i + 1] = s[i][i];
    }

}
signed main()
{
    int tt; cin >> tt >> k;
    init();
    while (tt--) {
        int n, m; cin >> n >> m;
        if (m > n) m = n;
        cout << s[n][m] << "\n";
    }
    return 0;
}

