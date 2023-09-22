/*************************************************************************
	> File Name: 1865.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 18 17:40:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> vis(m + 1, false);
    vis[1] = vis[0] = true;
    for (int i = 2; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            vis[j] = true;
        }
    }
    vector<int> res(m + 1);
    for (int i = 1; i <= m; i++) {
        res[i] = res[i - 1] + (!vis[i]);
    }
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        if (1 <= l and r <= m) {
            cout << res[r] - res[l - 1] << "\n";
        }
        else {
            cout << "Crossing the line\n";
            continue;
        }
    }
    return 0;
}

