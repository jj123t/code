/*************************************************************************
	> File Name: 1196.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 17:32:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> siz(N), par(N), pfx(N);
void init(int n) {
    for (int i = 1; i <= n; i++) siz[i] = 1, par[i] = i, pfx[i] = 0;
}
int Find(int x) {
    if (x == par[x]) return x;
    else {
        int t = par[x];
        par[x] = Find(par[x]);
        pfx[x] += pfx[t];
        siz[x] = siz[par[x]];
        return par[x];
    }
}
void Unite(int x, int y) {
    int a = Find(x), b = Find(y);
    par[a] = b;
    pfx[a] += siz[b];
    siz[a] += siz[b];
    siz[b] = siz[a];
}
int main()
{
    int n; cin >> n;
    init(30010);
    for (int i = 0; i < n; i++) {
        char op; int x, y; cin >> op >> x >> y;
        for (int i = 0; i <= 5; i++) cout << i << " : " << par[i] << " " << pfx[i] << " " << siz[i] << "\n";
        if (op == 'M') {
            Unite(x, y);
        }
        else {
            int a = Find(x);
            int b = Find(y);
            if (a == b) cout << abs(pfx[x] - pfx[y]) - 1 << "\n";
            else cout << -1 << "\n";
        }
    }
        for (int i = 0; i <= 5; i++) cout << i << " : " << par[i] << " " << pfx[i] << " " << siz[i] << "\n";
    return 0;
}

