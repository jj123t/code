/*************************************************************************
	> File Name: 2024.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 14:24:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int par[N * 3];
void init(int n) {
    for (int i = 1; i <= 3 * n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
int main()
{
    int n, k; cin >> n >> k;
    init(n);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int op, x, y; cin >> op >> x >> y;
        if (x > n or y > n) { ans++; continue; }
        if (op == 1) {
            if (same(x, y + n) or same(y, x + n)) {
                ans++;
            }
            else {
                Unite(x, y); Unite(x + n, y + n); Unite(x + 2 * n, y + 2 * n);
            }
        }
        else {
            if (same(x, y) or same(y + n, x))  {
                ans++;
            }
            else  {
                Unite(x + n, y); Unite(x + 2 * n, y + n); Unite(x, y + 2 * n);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

