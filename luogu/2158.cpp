/*************************************************************************
	> File Name: 2158.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 20:18:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> phi(n + 1);
    for (int i = 1; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        ans += phi[i];
    }
    cout << ans * 2 + 3 << "\n";
    return 0;
}

