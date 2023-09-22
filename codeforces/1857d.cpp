/*************************************************************************
	> File Name: 1857d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 22:19:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
vector<int> par(N), siz(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, siz[i] = 1;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    int a = Find(x), b = Find(y);
    siz[b] += siz[a];
    par[a] = b;
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int> ;
        vector<P> arr(n);
        for (int i =0; i < n; i++) cin >> arr[i].first;
        for (int i = 0; i < n; i++) cin >> arr[i].second;
        int mx = -1e9 - 7;
        for (int i = 0; i < n; i++) {
            if (arr[i].first - arr[i].second > mx) {
                mx = arr[i].first - arr[i].second;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].first - arr[i].second == mx) {
                ans++;
            }
        }
        cout << ans << "\n";
        for (int i = 0; i < n; i++) {
            if (arr[i].first - arr[i].second == mx) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

