/*************************************************************************
	> File Name: 1111.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 11:11:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> par(N), siz(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, siz[i] = 1;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
bool same(int x, int y) {
    return Find(x) == Find(y);
}
int Unite(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    siz[a] += siz[b];
    par[b] = a;
    return siz[a];
}
int main()
{
    int n, m; cin >> n >> m;
    init(n);
    vector<array<int, 3>> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    sort(arr.begin(), arr.end());
    int ans = -1;
    for (int i = 0; i < m; i++) {
        auto [t, u, v] = arr[i];
        if (!same(u, v)) {
            int d = Unite(u, v);
            if (d == n) {
                ans = t;
                break;
            }
        } 
    }
    cout << ans << "\n";
    return 0;
}

