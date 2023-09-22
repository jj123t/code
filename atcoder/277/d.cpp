/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 04:19:01 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int N = 1e6 + 10;
vector<int> par(N, 0);
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
signed main () {
    int n, m; cin >> n >> m;
    iota(par.begin(), par.begin() + n + 1, 0);
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
        int j = (i + 1) % n;
        if (arr[i] == arr[j] || (arr[i] + 1) % m == arr[j]) {
            Unite(i, j);
        }
    }
    int mx = 0;
    vector<int> res(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x = Find(i);
        res[x] += arr[i];
        mx = max(mx, res[x]);
    }
    cout << s - mx;
    return 0;
}
