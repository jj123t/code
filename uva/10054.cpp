/*************************************************************************
	> File Name: 10054.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 14:24:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int in[60], e[60][60];
void fleury(int u) {
    for (int i = 1; i <= 50; i++) {
        if (e[u][i]) {
            e[u][i]--; e[i][u]--;
            fleury(i);
            cout << i << " " << u << "\n";
        }
    }
}
int main() 
{
    int qq; cin >> qq;
    for (int tt = 1; tt <= qq; tt++) {
        memset(in, 0, sizeof in);
        memset(e, 0, sizeof e);
        int n; cin >> n;
        int start;
        for (int i = 1; i <= n; i++) {
            int u, v; cin >> u >> v;
            start = u;
            e[u][v]++;
            e[v][u]++;
            in[u]++, in[v]++;
        }
        bool flag = true;
        for (int i = 1; i <= 50; i++) {
            if (in[i] % 2) {
                flag = false;
                break;
            }
        }
        cout << "Case #" << tt << "\n";
        if (!flag) {
            cout << "some beads may be lost\n";
        }
        else {
            fleury(start);
        }
        if (tt != qq) cout << "\n";
    }
    return 0;
}
