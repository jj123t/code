/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May  3 17:08:57 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
#define int long long 
signed main () {
    int l, r; cin >> l >> r;
    vector<int> arr(r + 1, 0);
    vector<int> vis(r + 1, false);
    for (int i = 2; i <= r; i++) {
        for (int j = i; j <= r; j += i) {
            if (j >= l) arr[i]++;
        }
    }
    int ans = 0;
    vector<int> f(r + 1, 0);
    for (int g = r; g >= 2; g--) {
        f[g] = arr[g] * arr[g];
        for (int j = 2 * g; j <= r; j += g) {
            f[g] -= f[j];
        }
        ans += f[g];
        if (g >= l) ans -= 2 * arr[g] - 1;
    }
    cout << ans;
    return 0;
}

