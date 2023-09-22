/*************************************************************************
	> File Name: 1525.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 23:16:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int par[N];
void init(int n) {
    for (int i = 1; i <= 2 * n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
int main()
{
    int n, m; cin >> n >> m;
    init(n);
    vector<array<int, 3>> arr(m);
    for (auto &[a, b, c] : arr) cin >> b >> c >> a;
    sort(arr.rbegin(), arr.rend());
    set<int> st;
    for (int i = 0; i < m; i++) {
        auto [c, a, b] = arr[i];
        if (same(a + n, b + n) or same(a, b)) {
            cout << c << "\n";
            return 0;
        }
        else {
            Unite(a + n, b);
            Unite(a, b + n);
        }
    }
    cout << 0 << "\n";
    return 0;
}

