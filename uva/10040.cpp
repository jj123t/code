/*************************************************************************
	> File Name: 10040.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 20 22:11:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int sq[25][(1 << 21)];
int vis[(1 << 20)][2];
void fleury(int n) {
    int base = (1 << (n - 2)) - 1, u = 0;
    stack<int> path;
    vector<int> circuit;
    path.push(u);
    memset(vis, 0, sizeof vis);

    while (!path.empty()) {
        int v = 0;
        for (v = 0; v <= 1; v++) if (!vis[u][v]) break;
        if (v <= 1) {
            path.push(u);
            vis[u][v] = true;
            u = ((u & base) << 1) + v;
        }
        else {
            circuit.push_back(u);
            u = path.top();
            path.pop();
        }
    }
    int bits = circuit.back();
    base = (1 << (n - 1)) - 1;
    for (int i = circuit.size() - 2, j = 0; i >= 0; i--, j++) {
        sq[n][j] = ((bits & base) << 1) + (circuit[i] & 1);
        bits = sq[n][j];
    }
}
int main()
{
    sq[1][0] = 0, sq[1][1] = 1;
    for (int i = 2; i <= 21; i++) {
        fleury(i);
    }
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        cout << sq[n][k] << "\n";
    }
    return 0;
}

