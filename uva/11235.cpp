/*************************************************************************
  > File Name: 11235.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sun Sep  3 16:39:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e9;
#define int long long 
void build(int p, int l, int r) {
    if (l == r) {
        res[l] = 1;
        L[arr[l]] = l;
        R[arr[r]] = l;
        return 0;
    }
    int mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

}
signed main() 
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        int q; cin >> q;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        build(1, 1, n);
        while (q--) {
            int l, r; cin >> l >> r;
            if (l > r) swap(l, r);
            cout << qry(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
